//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "mordant");
    addSpecification("description", "You have a rather critical, biting "
        "nature about your interactions with others.");
    addSpecification("root", "harsh");
    addSpecification("opposing root", "kind");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
}
