//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "imbecile");
        addSpecification("description", "You are an absolute moron. Actually, to say that you're a moron is unfair to morons. You been mercilessly bereft of the ravages of intelligence.");
        addSpecification("root", "unintelligent");
        addSpecification("opposing root", "intelligent");
        addSpecification("opinion", -10);
        addSpecification("penalty to intelligence", 5);
        addSpecification("cost", -2);
        "baseTrait"::reset(arg);
    }
}

