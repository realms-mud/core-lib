//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dye vat");
    addAlias("vat");
    addAlias("dyeing vat");
    addAlias("dye tub");

    addAdjectives(({ "large", "stained", "bubbling", "wooden",
        "iron-banded", "pungent", "deep", "stained", "old", "steaming" }));

    addDescriptionTemplate("a ##Adjective## dye vat filled with colored liquid");

    addItemTemplate(
        "The dye vat is a large wooden tub banded with iron, filled nearly "
        "to the brim with a deeply colored liquid. The wood is stained "
        "beyond hope of cleaning, and the air around it is thick with a "
        "sharp, pungent smell. Fabric samples hang on a line nearby, "
        "dripping color onto the stained floor."
    );

    addSomeLightDescriptionTemplate(
        "a dye vat stands in the work area, its contents a vivid color"
    );
    addDimLightDescriptionTemplate(
        "a large vat of dark liquid is visible, its rim stained"
    );
    addLowLightDescriptionTemplate(
        "a large tub of some liquid sits in the work area"
    );
    addNearDarkDescriptionTemplate(
        "a pungent chemical smell emanates from a large container nearby"
    );
}
