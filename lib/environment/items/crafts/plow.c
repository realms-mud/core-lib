//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("plow");
    addAlias("plough");
    addAlias("iron plow");
    addAlias("farm plow");

    addAdjectives(({ "iron-tipped", "heavy", "weathered", "well-used",
        "mud-caked", "old", "sturdy", "rustic", "wooden", "simple" }));

    addDescriptionTemplate("a ##Adjective## plow resting at the field's edge");

    addItemTemplate(
        "The plow is a heavy wooden frame fitted with an iron share and "
        "coulter, designed to be drawn by ox or horse. The share is worn "
        "bright where it cuts the earth, and the handles are polished "
        "smooth by the grip of the plowman. Dried mud clings to every "
        "surface below the beam."
    );

    addSomeLightDescriptionTemplate(
        "a plow rests at the field's edge, its iron share bright from the soil"
    );
    addDimLightDescriptionTemplate(
        "a plow is visible at the field's edge, its iron faintly gleaming"
    );
    addLowLightDescriptionTemplate(
        "a large implement rests at the edge of the field"
    );
    addNearDarkDescriptionTemplate(
        "the smell of turned earth suggests farming equipment nearby"
    );
}
