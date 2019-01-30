//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected string WeaponType;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void AdditionalResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/soulspike.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/blood/soulspike.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/blood/root.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/blood/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/tortured-curse.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/blood/tortured-curse.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of Blood");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the knowledge to "
            "express their raw magical energy as blood magic.");
        Setup();

        if (WeaponType)
        {
            addResearchElement(sprintf("lib/guilds/scion/paths/%s/blood/root.c", WeaponType));
            TreeRoot(sprintf("lib/guilds/scion/paths/%s/blood/root.c", WeaponType));

            FirstLevel();
            ThirdLevel();
            SeventhLevel();
            EleventhLevel();
            FifteenthLevel();
            TwentyFirstLevel();
        }
    }
}
