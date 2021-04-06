//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/fighter/techniques/press-attack.c");

    addChild("guilds/fighter/techniques/press-attack.c",
        "guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/fighter/techniques/evade.c");

    addChild("guilds/fighter/techniques/evade.c",
        "guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/fighter/techniques/precision-attack.c");

    addChild("guilds/fighter/techniques/precision-attack.c",
        "guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/fighter/techniques/feint.c");

    addChild("guilds/fighter/techniques/feint.c",
        "guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/fighter/techniques/goad.c");

    addChild("guilds/fighter/techniques/goad.c",
        "guilds/fighter/techniques/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Combat Techniques");
        Description("");
        Source("fighter");
        addResearchElement("guilds/fighter/techniques/root.c");
        TreeRoot("guilds/fighter/techniques/root.c");

        FirstLevel();
        SecondLevel();
        ThirdLevel();
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
        ThirtyThirdLevel();
        ThirtySeventhLevel();
    }
}
