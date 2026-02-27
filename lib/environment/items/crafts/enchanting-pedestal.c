//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("enchanting pedestal");
    addAlias("pedestal");
    addAlias("enchanting stand");
    addAlias("runed pedestal");

    addAdjectives(({ "stone", "rune-carved", "ancient", "polished",
        "glowing", "ornate", "marble", "mystical", "dark", "imposing" }));

    addDescriptionTemplate("a ##Adjective## enchanting pedestal covered in runes");

    addItemTemplate(
        "The enchanting pedestal is a waist-high column of polished dark "
        "stone, its surface covered in deeply carved runes that seem to "
        "shift and writhe at the edge of vision. The flat top is slightly "
        "concave, designed to cradle objects during the enchanting process. "
        "A faint hum of energy vibrates through the stone."
    );

    addSomeLightDescriptionTemplate(
        "an enchanting pedestal stands in the center of the room, its runes "
        "faintly glowing"
    );
    addDimLightDescriptionTemplate(
        "a rune-carved pedestal is visible, its surface faintly luminous"
    );
    addLowLightDescriptionTemplate(
        "a pillar with faintly glowing markings stands in the room"
    );
    addNearDarkDescriptionTemplate(
        "faint runic light traces patterns on a stone column"
    );
}
