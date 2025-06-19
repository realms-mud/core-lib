//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("buffet");
    addAlias("sideboard");
    addAlias("serving table");
    addAlias("wooden buffet");

    addAdjectives(({ "long", "wooden", "carved", "broad", "sturdy",
        "old", "polished", "ornate", "functional" }));

    addDescriptionTemplate("a ##Adjective## buffet with cabinets and drawers");

    addItemTemplate(
        "This buffet is a long, low piece of furniture with cabinets "
        "and drawers beneath a broad serving surface. The wood is carved with "
        "simple designs, and the handles are made of wrought iron."
    );

    addSomeLightDescriptionTemplate(
        "a wooden buffet stands along the wall, its surface ready for serving "
        "food or drink"
    );
    addDimLightDescriptionTemplate(
        "a buffet is visible in the gloom, its outline broad and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a buffet can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a buffet is present, but details are lost in "
        "the darkness"
    );
}
