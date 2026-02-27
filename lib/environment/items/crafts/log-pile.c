//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("log pile");
    addAlias("logs");
    addAlias("timber pile");
    addAlias("raw logs");

    addAdjectives(({ "large", "bark-covered", "rough", "stacked",
        "fresh-felled", "mossy", "massive", "weathered", "sorted",
        "heavy" }));

    addDescriptionTemplate("a ##Adjective## pile of raw logs awaiting the saw");

    addItemTemplate(
        "The log pile is a stack of raw tree trunks, their bark still "
        "intact and their ends showing the pale rings of freshly sawn "
        "or axe-cut wood. They are stacked on skids to keep them off "
        "the damp ground, and iron dogs driven into the ends prevent "
        "them from rolling. Sap still weeps from the freshest cuts."
    );

    addSomeLightDescriptionTemplate(
        "a pile of raw logs is stacked on skids, sap weeping from fresh cuts"
    );
    addDimLightDescriptionTemplate(
        "a stack of large logs is visible, their bark dark and rough"
    );
    addLowLightDescriptionTemplate(
        "a large stack of cylindrical shapes suggests logs or timber"
    );
    addNearDarkDescriptionTemplate(
        "the sharp scent of tree sap and raw wood fills the air"
    );
}
