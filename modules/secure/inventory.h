//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int money;

private nosave string ArmorBlueprint = "lib/items/armor.c";
private nosave string WeaponBlueprint = "lib/items/weapon.c";
private nosave string ModifierBlueprint = "lib/items/modifierObject.c";
private nosave int weight = 0;

private nosave string Cyan = "[0;36m%s[0m";
private nosave string BoldBlack = "[0;30;1m%s[0m";
private nosave string Red = "[0;31m%s[0m";

private mapping itemRegistry =
([
    "equipped":([
        "wielded primary":0,
            "wielded offhand" : 0,
            "armor" : 0,
            "gloves" : 0,
            "helmet" : 0,
            "boots" : 0,
            "ring 1" : 0,
            "ring 2" : 0,
            "cloak" : 0,
            "amulet" : 0,
            "belt" : 0,
            "arm greaves" : 0,
            "leg greaves" : 0,
            "bracers" : 0
    ]),
        "guild objects": ([
        ])
]);