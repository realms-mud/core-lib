//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "stutterer");
    addSpecification("description", "You h-h-have a vocal tick that "
        "causes you to involuntarily repeat certain sounds while you talk.");
    addSpecification("root", "low self-esteem");
    addSpecification("opposing root", "high self-esteem");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -5);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to intimidation", 2);
    addSpecification("penalty to bluff", 1);
}
