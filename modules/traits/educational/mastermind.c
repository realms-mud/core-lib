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
        addSpecification("name", "mastermind");
        addSpecification("description", "You are a brilliant tactician regardless of what you put your mind to.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 25);
        addSpecification("opposing opinion", 10);
        addSpecification("bonus intelligence", 3);
        addSpecification("bonus wisdom", 3);
        addSpecification("bonus ancient history", 2);
        addSpecification("bonus local history", 2);
        addSpecification("bonus astronomy", 1);
        addSpecification("bonus chemistry", 1);
        addSpecification("bonus engineering", 1);
        addSpecification("bonus geology", 1);
        addSpecification("bonus mathematics", 2);
        addSpecification("bonus linguistics", 2);
        addSpecification("bonus philosophy", 1);
        addSpecification("bonus physics", 1);
        addSpecification("bonus etiquette", 1);
        addSpecification("bonus persuasion", 1);
        addSpecification("bonus diplomacy", 1);
        addSpecification("bonus spellcraft", 5);
        addSpecification("bonus reading", 2);
        addSpecification("bonus writing", 2);
        addSpecification("bonus perception", 5);
        addSpecification("bonus attack", 10);
        addSpecification("bonus defense", 10);
        addSpecification("cost", 5);
        "baseTrait"::reset(arg);
    }
}

