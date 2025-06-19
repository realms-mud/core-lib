//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("magical ice deposit");
    addAdjectives(({
        "glittering magical ice with a frosty sheen",
        "vein of magical ice with crystalline clusters",
        "magical ice seam with swirling frost patterns",
        "rough magical ice outcrop with jagged edges",
        "hidden magical ice seam barely visible in the wall",
        "magical ice deposit with radiant, icy hues",
        "magical ice with a glossy, enchanted surface",
        "vein of magical ice with sparkling inclusions",
        "magical ice seam with a mix of rough and polished stone",
        "deposit of magical ice with arcane inclusions",
        "irregular magical ice vein with pockets of pure frost",
        "magical ice with a luminous, chilling glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit magical ice deposit, where only the outline of the ice can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit magical ice deposit, its frosty colors blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible magical ice deposit, its arcane chill and icy glow "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("magical ice", 6, "/lib/instances/items/materials/crystal/magical-ice.c",
        "A deposit of magical ice runs through the rock here. Some remains.",
        ({ "crystal", "ice", "vein", "deposit" }));
    harvestRequiresTool("magical ice", "pick axe");
}
