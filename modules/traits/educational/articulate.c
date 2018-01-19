//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "educational");
        addSpecification("name", "articulate");
        addSpecification("description", "You are very well-spoken and eloquent. You also have a knack for reading your audience.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 25);
        addSpecification("bonus charisma", 2);
        addSpecification("bonus perception", 2);
        addSpecification("bonus ancient history", 1);
        addSpecification("bonus linguistics", 5);
        addSpecification("bonus philosophy", 2);
        addSpecification("bonus etiquette", 1);
        addSpecification("bonus local history", 1);
        addSpecification("bonus persuasion", 5);
        addSpecification("bonus barter", 1);
        addSpecification("bonus diplomacy", 1);
        addSpecification("bonus reading", 1);
        addSpecification("bonus writing", 1);
        addSpecification("cost", 3);
        "baseTrait"::reset(arg);
    }
}
