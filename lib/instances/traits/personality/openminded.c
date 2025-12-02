//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "open-minded");
    addSpecification("description", "You are a free thinker who is very "
        "open to considering the arguments of others.");
    addSpecification("root", "open-minded");
    addSpecification("opinion", 15);
    addSpecification("bonus diplomacy", 1);
}
