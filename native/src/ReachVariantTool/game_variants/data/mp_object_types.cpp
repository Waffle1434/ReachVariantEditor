#include "mp_object_types.h"
#include <stdexcept>

namespace {
   MPObjectTypeDefinition _instances[] = {
      MPObjectTypeDefinition("Spartan Biped",   'bipd', "objects/characters/spartans/spartans"),
      MPObjectTypeDefinition("Elite Biped",     'bipd', "objects/characters/elite/elite"),
      MPObjectTypeDefinition("Monitor Biped",   'bipd', "objects/characters/monitor/monitor_editor"),
      MPObjectTypeDefinition("Flag",            'weap', "objects/weapons/multiplayer/flag/flag"),
      MPObjectTypeDefinition("Bomb",            'weap', "objects/weapons/multiplayer/assault_bomb/assault_bomb"),
      MPObjectTypeDefinition("Ball",            'weap', "objects/weapons/multiplayer/skull/skull"),
      MPObjectTypeDefinition("Hill Beacon",     'bloc', "objects/multi/models/mp_hill_beacon/mp_hill_beacon"),
      MPObjectTypeDefinition("Flag Stand",      'bloc', "objects/multi/models/mp_flag_base/mp_flag_base"),
      MPObjectTypeDefinition("Hill Marker",     'bloc', "objects/multi/models/mp_circle/mp_circle"),
      MPObjectTypeDefinition("Frag Grenade",    'eqip', "objects/weapons/grenade/frag_grenade/frag_grenade"),
      MPObjectTypeDefinition("Plasma grenade",  'eqip', "objects/weapons/grenade/plasma_grenade/plasma_grenade"),
      MPObjectTypeDefinition("Unused (Spike Grenade)"),
      MPObjectTypeDefinition("Unused (Firebomb Grenade)"),
      MPObjectTypeDefinition("DMR",             'weap', "objects/weapons/rifle/dmr/dmr"),
      MPObjectTypeDefinition("Assault Rifle",   'weap', "objects/weapons/rifle/assault_rifle/assault_rifle"),
      MPObjectTypeDefinition("Plasma Pistol",   'weap', "objects/weapons/pistol/plasma_pistol/plasma_pistol"),
      MPObjectTypeDefinition("Spiker",          'weap', "objects/weapons/rifle/spike_rifle/spike_rifle"),
      MPObjectTypeDefinition("Unused (SMG)"),
      MPObjectTypeDefinition("Needle Rifle",    'weap', "objects/weapons/rifle/needle_rifle/needle_rifle"),
      MPObjectTypeDefinition("Plasma Repeater", 'weap', "objects/weapons/rifle/plasma_repeater/plasma_repeater"),
      MPObjectTypeDefinition("Energy Sword",    'weap', "objects/weapons/melee/energy_sword/energy_sword"),
      MPObjectTypeDefinition("Magnum",          'weap', "objects/weapons/pistol/magnum/magnum"),
      MPObjectTypeDefinition("Needler",         'weap', "objects/weapons/pistol/needler/needler"),
      MPObjectTypeDefinition("Plasma Rifle",    'weap', "objects/weapons/rifle/plasma_rifle/plasma_rifle"),
      MPObjectTypeDefinition("Rocket Launcher", 'weap', "objects/weapons/support_high/rocket_launcher/rocket_launcher"),
      MPObjectTypeDefinition("Shotgun",         'weap', "objects/weapons/rifle/shotgun/shotgun"),
      MPObjectTypeDefinition("Sniper_rifle",    'weap', "objects/weapons/rifle/sniper_rifle/sniper_rifle"),
      MPObjectTypeDefinition("Unused (Brute Shot)"),
      MPObjectTypeDefinition("Beam Rifle",      'weap', "objects/weapons/rifle/focus_rifle/focus_rifle"),
      MPObjectTypeDefinition("Spartan Laser",   'weap', "objects/weapons/support_high/spartan_laser/spartan_laser"),
      MPObjectTypeDefinition("Gravity Hammer",  'weap', "objects/weapons/melee/gravity_hammer/gravity_hammer"),
      MPObjectTypeDefinition("Unused (Mauler)"),
      MPObjectTypeDefinition("Unused (Flamethrower)"),
      MPObjectTypeDefinition("Unused (Missile Pod)"),
      MPObjectTypeDefinition("Warthog",         'vehi', "objects/vehicles/human/warthog/warthog"),
      MPObjectTypeDefinition("Ghost",           'vehi', "objects/vehicles/covenant/ghost/ghost"),
      MPObjectTypeDefinition("Scorpion",        'vehi', "objects/vehicles/human/scorpion/scorpion"),
      MPObjectTypeDefinition("Wraith",          'vehi', "objects/vehicles/covenant/wraith/wraith"),
      MPObjectTypeDefinition("Banshee",         'vehi', "objects/vehicles/covenant/banshee/banshee"),
      MPObjectTypeDefinition("Mongoose",        'vehi', "objects/vehicles/human/mongoose/mongoose"),
      MPObjectTypeDefinition("Unused (Chopper)"),
      MPObjectTypeDefinition("Unused (Prowler)"),
      MPObjectTypeDefinition("Unused (Hornet)"),
      MPObjectTypeDefinition("Unused (Stingray)", 'vehi'),
      MPObjectTypeDefinition("Wraith (Heavy)", 'vehi'),
      MPObjectTypeDefinition("Falcon", 'vehi', "objects/vehicles/human/falcon/falcon"),
      MPObjectTypeDefinition("Sabre", 'vehi'),
      MPObjectTypeDefinition("Sprint", 'eqip', "objects/equipment/sprint/sprint"),
      MPObjectTypeDefinition("Jetpack", 'eqip', "objects/equipment/jet_pack/jet_pack"),
      MPObjectTypeDefinition("Armor Lock", 'eqip', "objects/equipment/armor_lockup/armor_lockup"),
      MPObjectTypeDefinition("Unused (Power Fist AA)", 'eqip'),
      MPObjectTypeDefinition("Active Camo (Armor Ability)", 'eqip', "objects/equipment/active_camouflage/active_camouflage"),
      MPObjectTypeDefinition("Unused (Ammo Pack AA)", 'eqip'),
      MPObjectTypeDefinition("Unused (Sensor Pack AA)", 'eqip'),
      MPObjectTypeDefinition("Revenant", 'vehi'),
      MPObjectTypeDefinition("pickup", 'vehi'),
      MPObjectTypeDefinition("Focus Rifle",          'weap', "objects/weapons/rifle/focus_rifle/focus_rifle"),
      MPObjectTypeDefinition("territory_static",     'bloc'),
      MPObjectTypeDefinition("ctf_flag_return_area", 'bloc'),
      MPObjectTypeDefinition("ctf_flag_spawn_point", 'bloc'),
      MPObjectTypeDefinition("Respawn Zone",         'scen', "objects/multi/spawning/respawn_zone"),
      MPObjectTypeDefinition("invasion_elite_buy",   'bloc'),
      MPObjectTypeDefinition("invasion_elite_drop",  'bloc'),
      MPObjectTypeDefinition("invasion_slayer",      'bloc'),
      MPObjectTypeDefinition("invasion_spartan_buy", 'bloc'),
      MPObjectTypeDefinition("invasion_spartan_drop", 'bloc'),
      MPObjectTypeDefinition("invasion_spawn_controller", 'bloc'),
      MPObjectTypeDefinition("oddball_ball_spawn_point", 'bloc'),
      MPObjectTypeDefinition("Plasma Launcher", 'weap', "objects/weapons/support_high/plasma_launcher/plasma_launcher"),
      MPObjectTypeDefinition("Fusion Coil", 'bloc', "objects/gear/human/military/fusion_coil/fusion_coil"),
      MPObjectTypeDefinition("unsc_shield_generator", 'scen'),
      MPObjectTypeDefinition("cov_shield_generator", 'scen'),
      MPObjectTypeDefinition("Initial Spawn Point", 'scen', "objects/multi/spawning/initial_spawn_point"),
      MPObjectTypeDefinition("invasion_vehicle_req", 'bloc'),
      MPObjectTypeDefinition("vehicle_req_floor", 'mach'),
      MPObjectTypeDefinition("wall_switch", 'ctrl'),
      MPObjectTypeDefinition("Health Pack", 'ctrl', "objects/levels/shared/device_controls/health_station/health_station"),
      MPObjectTypeDefinition("req_unsc_laser", 'mach'),
      MPObjectTypeDefinition("req_unsc_dmr", 'mach'),
      MPObjectTypeDefinition("req_unsc_rocket", 'mach'),
      MPObjectTypeDefinition("req_unsc_shotgun", 'mach'),
      MPObjectTypeDefinition("req_unsc_sniper", 'mach'),
      MPObjectTypeDefinition("req_covy_launcher", 'mach'),
      MPObjectTypeDefinition("req_covy_needler", 'mach'),
      MPObjectTypeDefinition("req_covy_sniper", 'mach'),
      MPObjectTypeDefinition("req_covy_sword", 'mach'),
      MPObjectTypeDefinition("shock_loadout", 'eqip'),
      MPObjectTypeDefinition("specialist_loadout", 'eqip'),
      MPObjectTypeDefinition("assassin_loadout", 'eqip'),
      MPObjectTypeDefinition("infiltrator_loadout", 'eqip'),
      MPObjectTypeDefinition("warrior_loadout", 'eqip'),
      MPObjectTypeDefinition("combatant_loadout", 'eqip'),
      MPObjectTypeDefinition("engineer_loadout", 'eqip'),
      MPObjectTypeDefinition("infantry_loadout", 'eqip'),
      MPObjectTypeDefinition("operator_loadout", 'eqip'),
      MPObjectTypeDefinition("recon_loadout", 'eqip'),
      MPObjectTypeDefinition("scout_loadout", 'eqip'),
      MPObjectTypeDefinition("seeker_loadout", 'eqip'),
      MPObjectTypeDefinition("airborne_loadout", 'eqip'),
      MPObjectTypeDefinition("ranger_loadout", 'eqip'),
      MPObjectTypeDefinition("req_buy_banshee", 'ctrl'),
      MPObjectTypeDefinition("req_buy_falcon", 'ctrl'),
      MPObjectTypeDefinition("req_buy_ghost", 'ctrl'),
      MPObjectTypeDefinition("req_buy_mongoose", 'ctrl'),
      MPObjectTypeDefinition("req_buy_revenant", 'ctrl'),
      MPObjectTypeDefinition("req_buy_scorpion", 'ctrl'),
      MPObjectTypeDefinition("req_buy_warthog", 'ctrl'),
      MPObjectTypeDefinition("req_buy_wraith", 'ctrl'),
      MPObjectTypeDefinition("fireteam_1_respawn_zone", 'scen'),
      MPObjectTypeDefinition("fireteam_2_respawn_zone", 'scen'),
      MPObjectTypeDefinition("fireteam_3_respawn_zone", 'scen'),
      MPObjectTypeDefinition("fireteam_4_respawn_zone", 'scen'),
      MPObjectTypeDefinition("semi", 'vehi'),
      MPObjectTypeDefinition("Soccer Ball", 'bloc', "objects/levels/shared/soccer_ball/soccer_ball"),
      MPObjectTypeDefinition("Golf Ball", 'bloc', "objects/levels/shared/golf_ball/golf_ball"),
      MPObjectTypeDefinition("golf_ball_blue", 'bloc'),
      MPObjectTypeDefinition("golf_ball_red", 'bloc'),
      MPObjectTypeDefinition("Golf Club", 'weap', "objects/levels/shared/golf_club/golf_club"),
      MPObjectTypeDefinition("Golf Cup", 'bloc', "objects/levels/shared/golf_cup/golf_cup"),
      MPObjectTypeDefinition("golf_tee", 'bloc'),
      MPObjectTypeDefinition("Dice", 'bloc', "objects/multi/dice/dice"),
      MPObjectTypeDefinition("space_crate", 'bloc'),
      MPObjectTypeDefinition("eradicator_loadout", 'eqip'),
      MPObjectTypeDefinition("saboteur_loadout", 'eqip'),
      MPObjectTypeDefinition("grenadier_loadout", 'eqip'),
      MPObjectTypeDefinition("marksman_loadout", 'eqip'),
      MPObjectTypeDefinition("flare", 'bloc'),
      MPObjectTypeDefinition("glow_stick", 'bloc'),
      MPObjectTypeDefinition("Concussion Rifle", 'weap', "objects/weapons/rifle/concussion_rifle/concussion_rifle"),
      MPObjectTypeDefinition("Grenade Launcher", 'weap', "objects/weapons/rifle/grenade_launcher/grenade_launcher"),
      MPObjectTypeDefinition("phantom_approach", 'mach'),
      MPObjectTypeDefinition("Hologram", 'eqip', "objects/equipment/hologram/hologram"),
      MPObjectTypeDefinition("Evade", 'eqip', "objects/equipment/evade/evade"),
      MPObjectTypeDefinition("unsc_data_core", 'weap', "objects/weapons/multiplayer/unsc_data_core/unsc_data_core"),
      MPObjectTypeDefinition("danger_zone", 'bloc', "objects/multi/spawning/danger_zone"),
      MPObjectTypeDefinition("teleporter_sender", 'bloc'),
      MPObjectTypeDefinition("teleporter_reciever", 'bloc'),
      MPObjectTypeDefinition("teleporter_2way", 'bloc'),
      MPObjectTypeDefinition("data_core_beam", 'mach'),
      MPObjectTypeDefinition("phantom_overwatch", 'mach'),
      MPObjectTypeDefinition("longsword", 'mach'),
      MPObjectTypeDefinition("Particle Emitter (Fire)", 'scen', "objects/multi/invisible_cube_of_derek/invisible_cube_of_derek"),
      MPObjectTypeDefinition("phantom_scenery", 'scen'),
      MPObjectTypeDefinition("pelican_scenery", 'scen'),
      MPObjectTypeDefinition("phantom", 'vehi'),
      MPObjectTypeDefinition("pelican", 'mach'),
      MPObjectTypeDefinition("armory_shelf", 'scen'),
      MPObjectTypeDefinition("cov_resupply_capsule", 'scen'),
      MPObjectTypeDefinition("covy_drop_pod", 'mach'),
      MPObjectTypeDefinition("invisible_marker", 'bloc'),
      MPObjectTypeDefinition("Respawn Zone (Weak)", 'scen', "objects/multi/spawning/weak_respawn_zone"),
      MPObjectTypeDefinition("Respawn Zone (Weak Anti)", 'scen', "objects/multi/spawning/weak_anti_respawn_zone"),
      MPObjectTypeDefinition("phantom_device", 'mach', "objects/vehicles/covenant/phantom/phantom"),
      MPObjectTypeDefinition("resupply_capsule", 'scen'),
      MPObjectTypeDefinition("resupply_capsule_open", 'scen'),
      MPObjectTypeDefinition("weapon_box", 'scen'),
      MPObjectTypeDefinition("tech_console_stationary", 'mach'),
      MPObjectTypeDefinition("tech_console_wall", 'mach'),
      MPObjectTypeDefinition("mp_cinematic_camera", 'scen', "objects/multi/generic/mp_cinematic_camera"),
      MPObjectTypeDefinition("invis_cov_resupply_capsule", 'mach'),
      MPObjectTypeDefinition("cov_power_module", 'weap', "objects/weapons/multiplayer/cov_power_module/cov_power_module"),
      MPObjectTypeDefinition("flak_cannon", 'weap', "objects/weapons/support_high/flak_cannon/flak_cannon"),
      MPObjectTypeDefinition("dropzone_boundary", 'bloc'),
      MPObjectTypeDefinition("shield_door_small", 'bloc'),
      MPObjectTypeDefinition("shield_door_medium", 'bloc'),
      MPObjectTypeDefinition("shield_door_large", 'bloc'),
      MPObjectTypeDefinition("Drop Shield (Armor Ability)", 'eqip', "objects/equipment/drop_shield/drop_shield"),
      MPObjectTypeDefinition("Machine Gun Turret (Detached)", 'weap', "objects/vehicles/human/turrets/machinegun/weapon/machinegun_turret/machinegun_turret"),
      MPObjectTypeDefinition("Machine Gun Turret", 'vehi', "objects/vehicles/human/turrets/machinegun/machinegun"),
      MPObjectTypeDefinition("Plasma Cannon (Detached)", 'weap', "objects/vehicles/covenant/turrets/plasma_turret/weapon/plasma_turret/plasma_turret"),
      MPObjectTypeDefinition("Plasma Cannon", 'vehi', "objects/vehicles/covenant/turrets/plasma_turret/plasma_turret_mounted"),
      MPObjectTypeDefinition("Shade Turret", 'vehi'),
      MPObjectTypeDefinition("cargo_truck", 'vehi'),
      MPObjectTypeDefinition("cart_electric", 'vehi'),
      MPObjectTypeDefinition("forklift", 'vehi'),
      MPObjectTypeDefinition("military_truck", 'vehi'),
      MPObjectTypeDefinition("oni_van", 'vehi'),
      MPObjectTypeDefinition("Warthog Turret (Normal)", 'vehi', "objects/vehicles/human/warthog/weapons/warthog_chaingun/warthog_chaingun"),
      MPObjectTypeDefinition("Warthog Turret (Gauss)", 'vehi', "objects/vehicles/human/warthog/weapons/warthog_gauss/warthog_gauss"),
      MPObjectTypeDefinition("Warthog Turret (Rocket)", 'vehi', "objects/vehicles/human/warthog/weapons/warthog_rocket/warthog_rocket"),
      MPObjectTypeDefinition("Scorpion Turret (Chaingun)", 'vehi', "objects/vehicles/human/scorpion/turrets/scorpion_anti_infantry/scorpion_anti_infantry"),
      MPObjectTypeDefinition("Falcon Turret (Grenade Left)", 'vehi', "objects/vehicles/human/falcon/turrets/falcon_side_grenade_left/falcon_side_grenade_left"),
      MPObjectTypeDefinition("Falcon Turret (Grenade Right)", 'vehi', "objects/vehicles/human/falcon/turrets/falcon_side_grenade_right/falcon_side_grenade_right"),
      MPObjectTypeDefinition("Wraith Turret (Anti-Infantry)", 'vehi', "objects/vehicles/covenant/wraith/turrets/wraith_anti_infantry/wraith_anti_infantry"),
      MPObjectTypeDefinition("Land Mine", 'bloc', "objects/multi/land_mine/land_mine"),
      MPObjectTypeDefinition("Target Locator", 'weap'),
      MPObjectTypeDefinition("ff_kill_zone", 'bloc'),
      MPObjectTypeDefinition("Block 1x1 Flat", 'bloc'),
      MPObjectTypeDefinition("Shade Turret (Anti-Air)", 'vehi'),
      MPObjectTypeDefinition("Shade Turret (Flak)", 'vehi'),
      MPObjectTypeDefinition("Shade Turret (Plasma)", 'vehi'),
      MPObjectTypeDefinition("Kill Ball", 'bloc', "objects/levels/shared/damage_sphere/damage_sphere"),
      MPObjectTypeDefinition("Forge Light (Red)",    'bloc', "objects/levels/forge/ff_light_red/ff_light_red"),
      MPObjectTypeDefinition("Forge Light (Blue)",   'bloc', "objects/levels/forge/ff_light_blue/ff_light_blue"),
      MPObjectTypeDefinition("Forge Light (Green)",  'bloc', "objects/levels/forge/ff_light_green/ff_light_green"),
      MPObjectTypeDefinition("Forge Light (Orange)", 'bloc', "objects/levels/forge/ff_light_orange/ff_light_orange"),
      MPObjectTypeDefinition("Forge Light (Purple)", 'bloc', "objects/levels/forge/ff_light_purple/ff_light_purple"),
      MPObjectTypeDefinition("Forge Light (Yellow)", 'bloc', "objects/levels/forge/ff_light_yellow/ff_light_yellow"),
      MPObjectTypeDefinition("Forge Light (White)",  'bloc', "objects/levels/forge/ff_light_white/ff_light_white"),
      MPObjectTypeDefinition("Forge Light (Flashing Red)",    'bloc', "objects/levels/forge/ff_light_flash_red/ff_light_flash_red"),
      MPObjectTypeDefinition("Forge Light (Flashing Yellow)", 'bloc', "objects/levels/forge/ff_light_flash_yellow/ff_light_flash_yellow"),
      MPObjectTypeDefinition("FX (Colorblind)", 'bloc', "objects/levels/shared/screen_fx_orb/fx/colorblind"),
      MPObjectTypeDefinition("FX (Gloomy)", 'bloc', "objects/levels/shared/screen_fx_orb/fx/gloomy"),
      MPObjectTypeDefinition("FX (Juicy)", 'bloc', "objects/levels/shared/screen_fx_orb/fx/juicy"),
      MPObjectTypeDefinition("FX (Nova)", 'bloc', "objects/levels/shared/screen_fx_orb/fx/nova"),
      MPObjectTypeDefinition("FX (Olde Timey)", 'bloc', "objects/levels/shared/screen_fx_orb/fx/olde_timey"),
      MPObjectTypeDefinition("FX (Pen And Ink)", 'bloc', "objects/levels/shared/screen_fx_orb/fx/pen_and_ink"),
      MPObjectTypeDefinition("fx_dusk", 'bloc'),
      MPObjectTypeDefinition("fx_golden_hour", 'bloc'),
      MPObjectTypeDefinition("fx_eerie", 'bloc'),
      MPObjectTypeDefinition("ff_grid", 'bloc'),
      MPObjectTypeDefinition("Invisible Cube of Alarming 1", 'scen', "objects/multi/invisible_cube_of_derek/invisible_cube_of_alarming_1"),
      MPObjectTypeDefinition("Invisible Cube of Alarming 2", 'scen', "objects/multi/invisible_cube_of_derek/invisible_cube_of_alarming_2"),
      MPObjectTypeDefinition("Safe Boundary",      'scen', "objects/multi/boundaries/safe_volume"),
      MPObjectTypeDefinition("Soft Safe Boundary", 'scen', "objects/multi/boundaries/soft_safe_volume"),
      MPObjectTypeDefinition("Kill Boundary",      'scen', "objects/multi/boundaries/kill_volume"),
      MPObjectTypeDefinition("Soft Kill Boundary", 'scen', "objects/multi/boundaries/soft_kill_volume"),
      MPObjectTypeDefinition("package_cabinet", 'mach'),
      MPObjectTypeDefinition("cov_powermodule_stand", 'mach'),
      MPObjectTypeDefinition("dlc_covenant_bomb", 'weap', "levels/multi/dlc/objects/dlc_covenant_bomb/dlc_covenant_bomb"),
      MPObjectTypeDefinition("dlc_invasion_heavy_shield", 'bloc', "levels/multi/dlc/objects/dlc_invasion_heavy_shield/dlc_invasion_heavy_shield"),
      MPObjectTypeDefinition("dlc_invasion_bomb_door", 'scen', "levels/multi/dlc/objects/dlc_invasion_bomb_door/dlc_invasion_bomb_door"),
   };
}
MPObjectTypeList::MPObjectTypeList() {
   this->list  = _instances;
   this->count = std::extent<decltype(_instances)>::value;
}
const MPObjectTypeDefinition& MPObjectTypeList::operator[](int i) const {
   if (i < 0 || i >= this->size())
      throw std::out_of_range("");
   return this->list[i];
}