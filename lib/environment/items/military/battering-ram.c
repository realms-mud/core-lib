//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("battering ram");
    addAlias("ram");
    addAlias("siege ram");

    addItemTemplate(
        "The battering ram is a massive log, its head bound with iron and "
        "suspended by chains from a sturdy wooden frame. The ground beneath is "
        "worn by the feet of many soldiers. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of a battering ram is barely visible, its bulk lost in "
        "the darkness"
    );
    addLowLightDescriptionTemplate(
        "a battering ram stands in the gloom, its iron head just visible"
    );
    addDimLightDescriptionTemplate(
        "the battering ram is faintly illuminated, its frame and chains "
        "apparent"
    );
    addSomeLightDescriptionTemplate(
        "the battering ram is clearly visible, its iron head and frame "
        "standing out"
    );
    addAdjectives(({ "massive", "iron-capped", "wooden", "siege", "wheeled" }));
    addDescriptionTemplate("a ##Adjective## battering ram with an iron-capped head");
}
