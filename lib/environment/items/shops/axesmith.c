//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("axesmith interior");

    addItemTemplate(
        "The axesmith's shop is a rugged, no-nonsense space built around a "
        "squat forge and a pair of scarred anvils. Heavy axes of every type "
        "line the walls - broad-bladed felling axes, bearded war axes, double-"
        "bitted woodsman's axes, and slender throwing hatchets. Hafts of ash "
        "and hickory stand bundled in a barrel, waiting to be fitted. The "
        "workbench holds drift punches, wedges, and a drawknife for shaping "
        "handles. A massive splitting stump sits near the entrance, its top "
        "embedded with test cuts, and the air smells of charcoal and fresh-cut "
        "wood."
    );

    addNearDarkDescriptionTemplate(
        "the axesmith's shop is swallowed by shadow, only the dull red glow "
        "of the forge hinting at the heavy shapes hanging from the walls"
    );
    addLowLightDescriptionTemplate(
        "the axes on the walls are dark, angular shapes in the gloom, the "
        "forge's fading light barely reaching the nearest blades"
    );
    addDimLightDescriptionTemplate(
        "enough light fills the shop to make out the distinctive profiles "
        "of the axes and the barrel of waiting hafts"
    );
    addSomeLightDescriptionTemplate(
        "the axesmith's shop is well-lit, the keen edges and varied shapes "
        "of the axes clearly visible along with the scarred splitting stump"
    );
    addDescriptionTemplate(
        "bright light catches the honed edges of every axe on the wall, "
        "and the grain of the ash hafts stands out in fine detail"
    );
}
