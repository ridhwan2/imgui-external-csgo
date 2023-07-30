#include "hacks.h"
#include "gui.h"
#include "globals.h"

#include <thread>

void hacks::VisualsThread(const Memory& mem) noexcept
{
	struct Vector2
	{
		float x = { }, y = { };
	};

	auto oldPunch = Vector2{ };

	while (gui::isRunning)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		const auto localPlayer = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwLocalPlayer);

		if (!localPlayer)
			continue;

		const auto glowManager = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwGlowObjectManager);

		if (!glowManager)
			continue;

		const auto localTeam = mem.Read<std::int32_t>(localPlayer + offsets::m_iTeamNum);

		for (auto i = 1; i <= 32; ++i)
		{
			const auto player = mem.Read<std::uintptr_t>(globals::clientAddress + offsets::dwEntityList + i * 0x10);

			if (!player)
				continue;

			const auto team = mem.Read<std::int32_t>(player + offsets::m_iTeamNum);

			if (team == localTeam)
				continue;

			const auto lifeState = mem.Read<std::int32_t>(player + offsets::m_lifeState);

			if (lifeState != 0)
				continue;

			if (globals::glow)
			{
				const auto glowIndex = mem.Read<std::int32_t>(player + offsets::m_iGlowIndex);

				mem.Write(glowManager + (glowIndex * 0x38) + 0x8, globals::glowColor[0]); // red
				mem.Write(glowManager + (glowIndex * 0x38) + 0xC, globals::glowColor[1]); // green
				mem.Write(glowManager + (glowIndex * 0x38) + 0x10, globals::glowColor[2]); // blue
				mem.Write(glowManager + (glowIndex * 0x38) + 0x14, globals::glowColor[3]); // alpha

				mem.Write(glowManager + (glowIndex * 0x38) + 0x28, true);
				mem.Write(glowManager + (glowIndex * 0x38) + 0x29, false);
			}

			if (globals::radar)
				mem.Write(player + offsets::m_bSpotted, true);

			if (globals::bhop)
			{
				auto mem = Memory("csgo.exe");
				const auto client = mem.GetModuleAddress("client.dll");

				const auto localPlayer = mem.Read<uintptr_t>(client + offsets::dwLocalPlayer);

				if (localPlayer)
				{
					const auto onGround = mem.Read<bool>(localPlayer + offsets::m_fFlags);

					if (GetAsyncKeyState(VK_SPACE) && onGround & (1 << 0))
						mem.Write<BYTE>(client + offsets::dwForceJump, 6);
				}
			}

			if (globals::rcs)
			{
				const auto memory = Memory{ "csgo.exe" };

				const auto client = memory.GetModuleAddress("client.dll");
				const auto engine = memory.GetModuleAddress("engine.dll");

				const auto& localPlayer = memory.Read<std::uintptr_t>(client + offsets::dwLocalPlayer);
				const auto& shotsFired = memory.Read<std::int32_t>(localPlayer + offsets::m_iShotsFired);

				if (shotsFired)
				{
					const auto& clientState = memory.Read<std::uintptr_t>(engine + offsets::dwClientState);
					const auto& viewAngles = memory.Read<Vector2>(clientState + offsets::dwClientState_ViewAngles);

					const auto& aimPunch = memory.Read<Vector2>(localPlayer + offsets::m_aimPunchAngle);

					auto newAngles = Vector2
					{
						viewAngles.x + oldPunch.x - aimPunch.x * 2.f,
						viewAngles.y + oldPunch.y - aimPunch.y * 2.f
					};

					if (newAngles.x > 89.f)
						newAngles.x = 89.f;

					if (newAngles.x < -89.f)
						newAngles.x = -89.f;

					while (newAngles.y > 180.f)
						newAngles.y -= 360.f;

					while (newAngles.y < -180.f)
						newAngles.y += 360.f;

					memory.Write<Vector2>(clientState + offsets::dwClientState_ViewAngles, newAngles);

					oldPunch.x = aimPunch.x * 2.f;
					oldPunch.y = aimPunch.y * 2.f;
				}
				else
				{
					oldPunch.x = oldPunch.y = 0.f;
				}
			}
		}
	}
}
