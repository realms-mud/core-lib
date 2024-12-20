//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/scion/avatars/common/evasion-i.c");
    addResearchElement("/guilds/scion/avatars/common/parry-i.c");
    addResearchElement("/guilds/scion/avatars/common/defense-i.c");

    addChild("/guilds/scion/avatars/common/evasion-i.c",
        "/guilds/scion/avatars/electricity/root.c");
    addChild("/guilds/scion/avatars/common/parry-i.c",
        "/guilds/scion/avatars/electricity/root.c");
    addChild("/guilds/scion/avatars/common/defense-i.c",
        "/guilds/scion/avatars/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/scion/avatars/common/spellcraft-i.c");
    addResearchElement("/guilds/scion/avatars/common/attack-i.c");
    addResearchElement("/guilds/scion/avatars/common/damage-i.c");

    addChild("/guilds/scion/avatars/common/spellcraft-i.c",
        "/guilds/scion/avatars/electricity/root.c");
    addChild("/guilds/scion/avatars/common/attack-i.c",
        "/guilds/scion/avatars/electricity/root.c");
    addChild("/guilds/scion/avatars/common/damage-i.c",
        "/guilds/scion/avatars/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/scion/avatars/electricity/shock-touch.c");

    addChild("/guilds/scion/avatars/electricity/shock-touch.c",
        "/guilds/scion/avatars/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/spellpoints-i.c");
    addResearchElement("/guilds/scion/avatars/common/hitpoints-i.c");

    addChild("/guilds/scion/avatars/common/spellpoints-i.c",
        "/guilds/scion/avatars/electricity/root.c");
    addChild("/guilds/scion/avatars/common/hitpoints-i.c",
        "/guilds/scion/avatars/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/scion/avatars/common/evasion-ii.c");
    addResearchElement("/guilds/scion/avatars/common/parry-ii.c");

    addChild("/guilds/scion/avatars/common/evasion-ii.c",
        "/guilds/scion/avatars/common/evasion-i.c");
    addChild("/guilds/scion/avatars/common/parry-ii.c",
        "/guilds/scion/avatars/common/parry-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/defense-ii.c");
    addResearchElement("/guilds/scion/avatars/common/attack-ii.c");

    addChild("/guilds/scion/avatars/common/defense-ii.c",
        "/guilds/scion/avatars/common/defense-i.c");
    addChild("/guilds/scion/avatars/common/attack-ii.c",
        "/guilds/scion/avatars/common/attack-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/spellcraft-ii.c");
    addResearchElement("/guilds/scion/avatars/common/damage-ii.c");

    addChild("/guilds/scion/avatars/common/spellcraft-ii.c",
        "/guilds/scion/avatars/common/spellcraft-i.c");
    addChild("/guilds/scion/avatars/common/damage-ii.c",
        "/guilds/scion/avatars/common/damage-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/scion/avatars/common/spellpoints-ii.c");
    addResearchElement("/guilds/scion/avatars/common/hitpoints-ii.c");

    addChild("/guilds/scion/avatars/common/spellpoints-ii.c",
        "/guilds/scion/avatars/common/spellpoints-i.c");
    addChild("/guilds/scion/avatars/common/hitpoints-ii.c",
        "/guilds/scion/avatars/common/hitpoints-i.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/scion/avatars/electricity/lightning.c");

    addChild("/guilds/scion/avatars/electricity/lightning.c",
        "/guilds/scion/avatars/electricity/shock-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/extra-attack.c");

    addChild("/guilds/scion/avatars/common/extra-attack.c",
        "/guilds/scion/avatars/common/attack-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/healing-rate-i.c");

    addChild("/guilds/scion/avatars/common/healing-rate-i.c",
        "/guilds/scion/avatars/common/hitpoints-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/evasion-iii.c");
    addResearchElement("/guilds/scion/avatars/common/parry-iii.c");

    addChild("/guilds/scion/avatars/common/evasion-iii.c",
        "/guilds/scion/avatars/common/evasion-ii.c");
    addChild("/guilds/scion/avatars/common/parry-iii.c",
        "/guilds/scion/avatars/common/parry-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/scion/avatars/common/defense-iii.c");
    addResearchElement("/guilds/scion/avatars/common/attack-iii.c");

    addChild("/guilds/scion/avatars/common/defense-iii.c",
        "/guilds/scion/avatars/common/defense-ii.c");
    addChild("/guilds/scion/avatars/common/attack-iii.c",
        "/guilds/scion/avatars/common/attack-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/scion/avatars/common/spellcraft-iii.c");
    addResearchElement("/guilds/scion/avatars/common/damage-iii.c");

    addChild("/guilds/scion/avatars/common/spellcraft-iii.c",
        "/guilds/scion/avatars/common/spellcraft-ii.c");
    addChild("/guilds/scion/avatars/common/damage-iii.c",
        "/guilds/scion/avatars/common/damage-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/spellpoints-iii.c");
    addResearchElement("/guilds/scion/avatars/common/hitpoints-iii.c");

    addChild("/guilds/scion/avatars/common/spellpoints-iii.c",
        "/guilds/scion/avatars/common/spellpoints-ii.c");
    addChild("/guilds/scion/avatars/common/hitpoints-iii.c",
        "/guilds/scion/avatars/common/hitpoints-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/scion/avatars/electricity/plasma-bolt.c");

    addChild("/guilds/scion/avatars/electricity/plasma-bolt.c",
        "/guilds/scion/avatars/electricity/lightning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/scion/avatars/common/extra-attack-ii.c");

    addChild("/guilds/scion/avatars/common/extra-attack-ii.c",
        "/guilds/scion/avatars/common/attack-iii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/scion/avatars/common/healing-rate-ii.c");

    addChild("/guilds/scion/avatars/common/healing-rate-ii.c",
        "/guilds/scion/avatars/common/hitpoints-iii.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Blood Avatar");
    Description("This skill tree provides the user with the knowledge "
        "to summon an avatar of electricity magic.");
    Source("Scion of Dhuras Guild");
    addResearchElement("/guilds/scion/avatars/electricity/root.c");
    TreeRoot("/guilds/scion/avatars/electricity/root.c");

    FirstLevel();
    ThirdLevel();
    FourthLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    TenthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
}
