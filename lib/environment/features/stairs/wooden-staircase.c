//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wooden staircase");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("staircase");
    addAlias("stair");
    addAlias("wooden");
    addAlias("wood");

    addAdjectives(({ "built from polished hardwood planks",
        "that creaks and groans with each step",
        "with an ornately carved banister",
        "showing the warm grain of seasoned oak",
        "that has been worn smooth by generations of use",
        "with steps that give slightly under weight",
        "made from rough-hewn timber",
        "with a simple rope handrail for support" }));

    addDescriptionTemplate("a wooden staircase ##Adjective## "
        "connects the different levels");
    addSomeLightDescriptionTemplate("a wooden staircase ##Adjective## "
        "provides access between floors");
    addNearDarkDescriptionTemplate("a wooden staircase can be heard "
        "creaking in the darkness");
    addLowLightDescriptionTemplate("a wooden staircase "
        "with worn planks connects the levels");
    addDimLightDescriptionTemplate("a wooden staircase ##Adjective## "
        "links the floors of the building");

    addItemTemplate("The wooden staircase is constructed of sturdy timber "
        "planks, each step carefully fitted and secured with iron nails. "
        "The wood shows the patina of age and use, with a handrail worn "
        "smooth by countless hands. Small gaps between boards allow air "
        "to circulate, and the entire structure creaks softly with movement, "
        "a characteristic sound of aged timber construction.");
}
