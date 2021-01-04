//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/eithagos.c");
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/nistaros.c");
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/nestegi.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/eithagos.c",
        "guilds/aegis-guard/forms/sword-attacks/attack-root.c");
    addChild("guilds/aegis-guard/forms/sword-attacks/nistaros.c",
        "guilds/aegis-guard/forms/sword-attacks/attack-root.c");
    addChild("guilds/aegis-guard/forms/sword-attacks/nestegi.c",
        "guilds/aegis-guard/forms/sword-attacks/nistaros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/ercho.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/ercho.c",
        "guilds/aegis-guard/forms/sword-attacks/eithagos.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/tharcuth.c");
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/diyacuth.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/tharcuth.c",
        "guilds/aegis-guard/forms/sword-attacks/attack-root.c");
    addChild("guilds/aegis-guard/forms/sword-attacks/diyacuth.c",
        "guilds/aegis-guard/forms/sword-attacks/attack-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/esgeri.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/esgeri.c",
        "guilds/aegis-guard/forms/sword-attacks/tharcuth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/dravnu.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/dravnu.c",
        "guilds/aegis-guard/forms/sword-attacks/eithagos.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/cirithu.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/cirithu.c",
        "guilds/aegis-guard/forms/sword-attacks/diyacuth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/dravo.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/dravo.c",
        "guilds/aegis-guard/forms/sword-attacks/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/thar-dravn.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/thar-dravn.c",
        "guilds/aegis-guard/forms/sword-attacks/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/enaidravn.c");
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/nuath-dravn.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/enaidravn.c",
        "guilds/aegis-guard/forms/sword-attacks/dravnu.c");
    addChild("guilds/aegis-guard/forms/sword-attacks/nuath-dravn.c",
        "guilds/aegis-guard/forms/sword-attacks/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/edaid-lhewig.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/edaid-lhewig.c",
        "guilds/aegis-guard/forms/sword-attacks/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/aucir.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/aucir.c",
        "guilds/aegis-guard/forms/sword-attacks/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/raica-dravn.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/raica-dravn.c",
        "guilds/aegis-guard/forms/sword-attacks/enaidravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/gwistamacil.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/gwistamacil.c",
        "guilds/aegis-guard/forms/sword-attacks/edaid-lhewig.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/ruth-dravn.c");
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/naetho.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/ruth-dravn.c",
        "guilds/aegis-guard/forms/sword-attacks/thar-dravn.c");
    addChild("guilds/aegis-guard/forms/sword-attacks/naetho.c",
        "guilds/aegis-guard/forms/sword-attacks/gwistamacil.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/lelyan-isilme.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/lelyan-isilme.c",
        "guilds/aegis-guard/forms/sword-attacks/nistaros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/lanna-dravn.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/lanna-dravn.c",
        "guilds/aegis-guard/forms/sword-attacks/thar-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/maetha.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/maetha.c",
        "guilds/aegis-guard/forms/sword-attacks/lanna-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/centhlein-dravn.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/centhlein-dravn.c",
        "guilds/aegis-guard/forms/sword-attacks/thar-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/asta-dravn.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/asta-dravn.c",
        "guilds/aegis-guard/forms/sword-attacks/thar-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/hasto.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/hasto.c",
        "guilds/aegis-guard/forms/sword-attacks/asta-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/maego.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/maego.c",
        "guilds/aegis-guard/forms/sword-attacks/maetha.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword-attacks/narcha.c");

    addChild("guilds/aegis-guard/forms/sword-attacks/narcha.c",
        "guilds/aegis-guard/forms/sword-attacks/hasto.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Maetha ai Megil");
        Description("");
        Source("Aegis Guard");
        addResearchElement("guilds/aegis-guard/forms/sword-attacks/attack-root.c");
        TreeRoot("guilds/aegis-guard/forms/sword-attacks/attack-root.c");

        FirstLevel();
        SecondLevel();
        ThirdLevel();
        FourthLevel();
        FifthLevel();
        SixthLevel();
        SeventhLevel();
        EighthLevel();
        NinthLevel();
        TenthLevel();
        TwelfthLevel();
        ThirteenLevel();
        FourteenLevel();
        FifteenthLevel();
        SixteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
        TwentiethLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtiethLevel();
        ThirtyFirstLevel();
    }
}
