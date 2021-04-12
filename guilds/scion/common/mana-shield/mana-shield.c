//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/gift-of-dhuras.c");

    addChild("/guilds/scion/common/mana-shield/gift-of-dhuras.c",
    "/guilds/scion/common/mana-shield/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/impenetrable-mana.c");

    addChild("/guilds/scion/common/mana-shield/impenetrable-mana.c",
    "/guilds/scion/common/mana-shield/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/boon-of-dhuras.c");
    addResearchElement("/guilds/scion/common/mana-shield/boon-of-lyndros.c");

    addChild("/guilds/scion/common/mana-shield/boon-of-dhuras.c",
    "/guilds/scion/common/mana-shield/gift-of-dhuras.c");
    addChild("/guilds/scion/common/mana-shield/boon-of-lyndros.c",
    "/guilds/scion/common/mana-shield/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mana-screen.c");

    addChild("/guilds/scion/common/mana-shield/mana-screen.c",
    "/guilds/scion/common/mana-shield/impenetrable-mana.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mana-shroud.c");

    addChild("/guilds/scion/common/mana-shield/mana-shroud.c",
    "/guilds/scion/common/mana-shield/boon-of-dhuras.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/veil-of-finiasc.c");

    addChild("/guilds/scion/common/mana-shield/veil-of-finiasc.c",
    "/guilds/scion/common/mana-shield/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/might-of-dhuras.c");

    addChild("/guilds/scion/common/mana-shield/might-of-dhuras.c",
    "/guilds/scion/common/mana-shield/boon-of-dhuras.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/hopes-embrace.c");
    addResearchElement("/guilds/scion/common/mana-shield/veil-of-lyndros.c");

    addChild("/guilds/scion/common/mana-shield/hopes-embrace.c",
    "/guilds/scion/common/mana-shield/mana-shroud.c");
    addChild("/guilds/scion/common/mana-shield/veil-of-lyndros.c",
    "/guilds/scion/common/mana-shield/boon-of-lyndros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mana-bulwark.c");

    addChild("/guilds/scion/common/mana-shield/mana-bulwark.c",
    "/guilds/scion/common/mana-shield/mana-screen.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/blessing-of-dhuras.c");

    addChild("/guilds/scion/common/mana-shield/blessing-of-dhuras.c",
    "/guilds/scion/common/mana-shield/hopes-embrace.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/shroud-of-finiasc.c");

    addChild("/guilds/scion/common/mana-shield/shroud-of-finiasc.c",
    "/guilds/scion/common/mana-shield/veil-of-finiasc.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/veil-of-llenwyn.c");

    addChild("/guilds/scion/common/mana-shield/veil-of-llenwyn.c",
    "/guilds/scion/common/mana-shield/might-of-dhuras.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mantle-of-lyndros.c");

    addChild("/guilds/scion/common/mana-shield/mantle-of-lyndros.c",
    "/guilds/scion/common/mana-shield/veil-of-lyndros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mantle-of-mana.c");

    addChild("/guilds/scion/common/mana-shield/mantle-of-mana.c",
    "/guilds/scion/common/mana-shield/mana-bulwark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mantle-of-finiasc.c");

    addChild("/guilds/scion/common/mana-shield/mantle-of-finiasc.c",
    "/guilds/scion/common/mana-shield/shroud-of-finiasc.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mantle-of-dhuras.c");

    addChild("/guilds/scion/common/mana-shield/mantle-of-dhuras.c",
    "/guilds/scion/common/mana-shield/veil-of-llenwyn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/bulwark-of-lyndros.c");

    addChild("/guilds/scion/common/mana-shield/bulwark-of-lyndros.c",
    "/guilds/scion/common/mana-shield/mantle-of-lyndros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/mana-veil.c");

    addChild("/guilds/scion/common/mana-shield/mana-veil.c",
    "/guilds/scion/common/mana-shield/mantle-of-mana.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/scion/common/mana-shield/bulwark-of-finiasc.c");

    addChild("/guilds/scion/common/mana-shield/bulwark-of-finiasc.c",
    "/guilds/scion/common/mana-shield/mantle-of-finiasc.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Mana Shield");
    Source("Scion of Dhuras Guild");
    Description("This skill provides the user with the "
        "knowledge to express their raw magical energy as a magical shield.");

    addResearchElement("/guilds/scion/common/mana-shield/root.c");
    TreeRoot("/guilds/scion/common/mana-shield/root.c");

    SeventhLevel();
    NinthLevel();
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
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortySeventhLevel();
}
