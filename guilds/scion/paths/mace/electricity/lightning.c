//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/electricity/lightning.c";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
    WeaponType = "mace";
    WeaponSkill = "mace";
    ValidWeaponTypes = ({ "mace", "flail" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
