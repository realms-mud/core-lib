//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "cynical");
    addSpecification("description", "You are a realist. You realize that "
        "the world is a harsh and cruel place - and it's all because of "
        "the idiots who populate it. People are lame, predictable monsters "
        "motivated only by their own self-interests. Those who claim "
        "otherwise are liars. Those who show charity or kindness, you "
        "treat with suspicion. Clearly, they have ulterior motives.");
    addSpecification("root", "pessimistic");
    addSpecification("opposing root", "optimistic");
    addSpecification("opinion", 15);
    addSpecification("opposing opinion", -15);
}
