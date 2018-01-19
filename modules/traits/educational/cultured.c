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
        addSpecification("name", "cultured");
        addSpecification("description", "You are very worldly - knowing how to talk to other peoples and appreciate the differences of different cultures.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", 5);
        addSpecification("bonus charisma", 1);
        addSpecification("bonus perception", 2);
        addSpecification("bonus ancient history", 3);
        addSpecification("bonus linguistics", 1);
        addSpecification("bonus etiquette", 1);
        addSpecification("bonus local history", 3);
        addSpecification("bonus persuasion", 2);
        addSpecification("bonus barter", 1);
        addSpecification("bonus diplomacy", 2);
        addSpecification("bonus reading", 1);
        addSpecification("bonus writing", 1);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}

