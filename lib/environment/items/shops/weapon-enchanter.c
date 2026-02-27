//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("weapon enchanter interior");

    addItemTemplate(
        "The weapon enchanter's workshop bridges the martial and the arcane. "
        "One side of the room resembles a smith's shop, with a forge whose "
        "flames burn an unnatural violet and an anvil engraved with binding "
        "sigils. The other side is an enchanter's workstation: racks of "
        "channeling crystals, vials of elemental essence, and sheaves of "
        "runic stencils. Weapons in various stages of enchantment rest in "
        "padded clamps along a central bench - a sword whose blade shimmers "
        "with frost, a mace trailing faint wisps of smoke, and a spear whose "
        "tip crackles with tiny sparks. The air tastes of copper and ozone."
    );

    addNearDarkDescriptionTemplate(
        "the weapon enchanter's workshop is dark save for the violet glow "
        "of the forge and the faint shimmer of a half-enchanted blade"
    );
    addLowLightDescriptionTemplate(
        "the unnatural flames of the forge cast purple-tinged shadows over "
        "the workbenches, and enchanted weapons pulse faintly in their clamps"
    );
    addDimLightDescriptionTemplate(
        "soft light mingles with the forge's violet glow, revealing the "
        "channeling crystals and the weapons clamped along the central bench"
    );
    addSomeLightDescriptionTemplate(
        "the workshop is bright enough to see the runic stencils and the "
        "elemental effects playing across the enchanted weapons"
    );
    addDescriptionTemplate(
        "light floods the weapon enchanter's workshop, making the crystals "
        "blaze and the enchanted blades shimmer with restrained power"
    );
}
