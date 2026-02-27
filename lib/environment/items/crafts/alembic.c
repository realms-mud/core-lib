//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("alembic");
    addAlias("still");
    addAlias("distillation apparatus");
    addAlias("retort");

    addAdjectives(({ "glass", "copper", "bubbling", "complex", "delicate",
        "coiled", "steaming", "intricate", "old", "well-used" }));

    addDescriptionTemplate("a ##Adjective## alembic connected by copper tubing");

    addItemTemplate(
        "The alembic is a distillation apparatus of glass flasks and "
        "copper tubing, its various vessels connected by coiled condensers "
        "and drip tubes. A small spirit flame heats the lower flask, "
        "sending vapors up through the apparatus to condense and collect "
        "as purified liquid. The whole arrangement bubbles and drips "
        "with quiet industry."
    );

    addSomeLightDescriptionTemplate(
        "an alembic bubbles and drips on the workbench, glass and copper "
        "gleaming"
    );
    addDimLightDescriptionTemplate(
        "a complex glass and copper apparatus bubbles quietly on a bench"
    );
    addLowLightDescriptionTemplate(
        "glass and metal shapes catch faint light on the workbench"
    );
    addNearDarkDescriptionTemplate(
        "a faint bubbling and the smell of distilled spirits fill the air"
    );
}
