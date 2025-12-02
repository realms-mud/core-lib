//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "witty");
    addSpecification("description", "You have a way with words - a sharp "
        "tongue and a quick wit.");
    addSpecification("root", "eloquent");
    addSpecification("opposing root", "vulgar");
    addSpecification("opinion", 10);
}
