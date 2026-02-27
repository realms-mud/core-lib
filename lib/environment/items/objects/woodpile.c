//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("woodpile");
    addAlias("firewood");
    addAlias("wood stack");
    addAlias("pile of firewood");

    addAdjectives(({ "neatly-stacked", "large", "seasoned", "split",
        "weathered", "fresh-cut", "dwindling", "towering", "well-kept",
        "bark-covered" }));

    addDescriptionTemplate("a ##Adjective## woodpile stacked against a wall");

    addItemTemplate(
        "The woodpile is a carefully stacked arrangement of split logs, "
        "their ends forming a mosaic of pale heartwood and dark bark. "
        "Wood chips and curls of bark litter the ground around its base, "
        "and the sharp scent of cut timber hangs in the air."
    );

    addSomeLightDescriptionTemplate(
        "a woodpile is stacked neatly, the pale ends of split logs visible"
    );
    addDimLightDescriptionTemplate(
        "a woodpile is visible against the wall, a rough stack of logs"
    );
    addLowLightDescriptionTemplate(
        "a dark mass stacked against the wall appears to be firewood"
    );
    addNearDarkDescriptionTemplate(
        "the scent of cut wood suggests a woodpile is stacked nearby"
    );
}
