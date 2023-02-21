//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "vapid");
    addSpecification("description", "You are a dull and tedious person. You offer little new insight to conversations and have very little intellectual curiosity.");
    addSpecification("root", "unintelligent");
    addSpecification("opposing root", "intelligent");
    addSpecification("opinion", -5);
    addSpecification("penalty to intelligence", 1);
    addSpecification("penalty to wisdom", 1);
    addSpecification("cost", -1);
}
