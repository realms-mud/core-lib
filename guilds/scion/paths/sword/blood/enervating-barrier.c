//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/enervating-barrier.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "sword";
    WeaponSkill = "long sword";

    addSpecification("limited by", (["equipment":({
        "long sword", "hand and a half sword", "two-handed sword" })]));
}
