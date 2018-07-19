//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef itemFormatters_h
#define itemFormatters_h

private nosave string Unidentified = "[0;36m%s[0m";
private nosave string UseIsPenalized = "[0;30;1m%s[0m";
private nosave string NormalEquipment = "[0;37;1m%s[0m";
private nosave string StrongEnchantment = "[0;35;1m%s[0m";
private nosave string SpecialAttack = "[0;31m%s[0m";
private nosave string WellCrafted = "[0;32m%s[0m";
private nosave string Value = "[0;33m%s[0m";
private nosave string Masterwork = "[0;32;1m%s[0m";
private nosave string Enchanted = "[0;35m%s[0m";

private nosave string Cyan = "[0;36m%s[0m";
private nosave string BoldBlack = "[0;30;1m%s[0m";
private nosave string Red = "[0;31m%s[0m";
private nosave string Green = "[0;32m%s[0m";
private nosave string Yellow = "[0;33m%s[0m";
private nosave string Blue = "[0;34m%s[0m";
private nosave string Magenta = "[0;35m%s[0m";

private nosave mapping decorators = ([
    "wizard levels":([
        "apprentice":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;133m",
            "24-bit": "\x1b[0;38;2;100;200;100m"
        ]),
        "wizard":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;200;200;200m"
        ]),
        "creator":([
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;212m",
            "24-bit": "\x1b[0;38;2;100;200;10m"
        ]),
        "highwizard":([
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;202m",
            "24-bit": "\x1b[0;38;2;10;200;100m"
        ]),
        "senior":([
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;199m",
            "24-bit": "\x1b[0;38;2;100;20;100m"
        ]),
        "admin":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;178m",
            "24-bit": "\x1b[0;38;2;200;20;100m"
        ]),
        "elder":([
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;220m",
            "24-bit": "\x1b[0;38;2;100;20;200m"
        ]),
        "sage":([
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;140m",
            "24-bit": "\x1b[0;38;2;100;20;10m"
        ]),
        "archwizard":([
            "3-bit": "\x1b[0;34m",
            "8-bit": "\x1b[0;38;5;240m",
            "24-bit": "\x1b[0;38;2;10;20;100m"
        ]),
        "demigod":([
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;90m",
            "24-bit": "\x1b[0;38;2;80;80;80m"
        ]),
        "god":([
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;111m",
            "24-bit": "\x1b[0;38;2;130;130;130m"
        ]),
        "owner":([
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
    ])
]);
#endif
