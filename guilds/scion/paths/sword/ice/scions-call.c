//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/ice/scions-call.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "sword";

    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));
}
