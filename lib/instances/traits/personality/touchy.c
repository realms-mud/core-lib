//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "touchy");
    addSpecification("description", "You have all the emotional grace "
        "of a fifteen year old girl. You tend to misconstrue others' "
        "words and actions, often reacting with extreme emotion.");
    addSpecification("root", "low self-esteem");
    addSpecification("opposing root", "high self-esteem");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -5);
    addSpecification("penalty to persuasion", 1);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("penalty to intimidation", 2);
    addSpecification("penalty to bluff", 1);
}
