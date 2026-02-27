//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseFire.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("camp fire");
    addAlias("fire");
    addAlias("campfire");
    suppressEntryMessage();

    addDescriptionTemplate("there are charred cinders and the ashen remains "
        "of a small campfire");
    addActiveSourceOfLight(8, "flickering tendrils of flame roil out from the "
        "newly-added logs of a small camp fire");

    addFireDescriptions(({
        "there are charred cinders and the ashen remains of a small campfire",
        "faint light emanates from the ashen embers of a small camp fire",
        "occasional flickers of red flame emanate from the faintly glowing red "
            "coals of a small camp fire",
        "faint flickers of red flame emanate from the nearly-spent logs of a "
            "small camp fire, its red coals feverishly glowing",
        "hisses come from the low flames of a small camp fire, its bed of coals "
            "hues of red, orange, and blue",
        "flames greedily wrap around the charred logs of a "
            "small camp fire, its bed of coals brilliant yellow and blue",
        "flames greedily ascend from a small camp fire that "
            "hisses and pops as water vapor escapes the logs it is consuming",
        "flickering tendrils of flame roil out from the slightly-charred logs of a "
            "small camp fire",
        "flickering tendrils of flame roil out from the newly-added logs of a "
            "small camp fire"
     }));

    addItemTemplate("the area around the campfire has been cleared away to "
        "place a barrier between the fire and other combustible objects. "
        "##UseDescriptionSet##");
}
