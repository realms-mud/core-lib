//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/eithagos.c");
    addResearchElement("guilds/aegis-guard/forms/sword/nistaros.c");
    addResearchElement("guilds/aegis-guard/forms/sword/nestegi.c");

    addChild("guilds/aegis-guard/forms/sword/eithagos.c",
        "guilds/aegis-guard/forms/sword/attack-root.c");
    addChild("guilds/aegis-guard/forms/sword/nistaros.c",
        "guilds/aegis-guard/forms/sword/attack-root.c");
    addChild("guilds/aegis-guard/forms/sword/nestegi.c",
        "guilds/aegis-guard/forms/sword/nistaros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/ercho.c");

    addChild("guilds/aegis-guard/forms/sword/ercho.c",
        "guilds/aegis-guard/forms/sword/eithagos.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/tharcuth.c");
    addResearchElement("guilds/aegis-guard/forms/sword/diyacuth.c");

    addChild("guilds/aegis-guard/forms/sword/tharcuth.c",
        "guilds/aegis-guard/forms/sword/attack-root.c");
    addChild("guilds/aegis-guard/forms/sword/diyacuth.c",
        "guilds/aegis-guard/forms/sword/attack-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/esgeri.c");

    addChild("guilds/aegis-guard/forms/sword/esgeri.c",
        "guilds/aegis-guard/forms/sword/tharcuth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/dravnu.c");

    addChild("guilds/aegis-guard/forms/sword/dravnu.c",
        "guilds/aegis-guard/forms/sword/eithagos.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/cirithu.c");

    addChild("guilds/aegis-guard/forms/sword/cirithu.c",
        "guilds/aegis-guard/forms/sword/diyacuth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/dravo.c");

    addChild("guilds/aegis-guard/forms/sword/dravo.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/thar-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/thar-dravn.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/enaidravn.c");
    addResearchElement("guilds/aegis-guard/forms/sword/nuath-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/enaidravn.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
    addChild("guilds/aegis-guard/forms/sword/nuath-dravn.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/edaid-lhewig.c");

    addChild("guilds/aegis-guard/forms/sword/edaid-lhewig.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/aucir.c");

    addChild("guilds/aegis-guard/forms/sword/aucir.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/raica-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/raica-dravn.c",
        "guilds/aegis-guard/forms/sword/enaidravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/gwistamacil.c");

    addChild("guilds/aegis-guard/forms/sword/gwistamacil.c",
        "guilds/aegis-guard/forms/sword/edaid-lhewig.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/ruth-dravn.c");
    addResearchElement("guilds/aegis-guard/forms/sword/naetho.c");

    addChild("guilds/aegis-guard/forms/sword/ruth-dravn.c",
        "guilds/aegis-guard/forms/sword/thar-dravn.c");
    addChild("guilds/aegis-guard/forms/sword/naetho.c",
        "guilds/aegis-guard/forms/sword/gwistamacil.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/lelyan-isilme.c");

    addChild("guilds/aegis-guard/forms/sword/lelyan-isilme.c",
        "guilds/aegis-guard/forms/sword/nistaros.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/lanna-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/lanna-dravn.c",
        "guilds/aegis-guard/forms/sword/thar-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/maetha.c");

    addChild("guilds/aegis-guard/forms/sword/maetha.c",
        "guilds/aegis-guard/forms/sword/lanna-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/centhlein-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/centhlein-dravn.c",
        "guilds/aegis-guard/forms/sword/thar-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/asta-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/asta-dravn.c",
        "guilds/aegis-guard/forms/sword/thar-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/hasto.c");

    addChild("guilds/aegis-guard/forms/sword/hasto.c",
        "guilds/aegis-guard/forms/sword/asta-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/maego.c");

    addChild("guilds/aegis-guard/forms/sword/maego.c",
        "guilds/aegis-guard/forms/sword/maetha.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/narcha.c");

    addChild("guilds/aegis-guard/forms/sword/narcha.c",
        "guilds/aegis-guard/forms/sword/hasto.c");
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
        addResearchElement("guilds/aegis-guard/forms/sword/attack-root.c");
        TreeRoot("guilds/aegis-guard/forms/sword/attack-root.c");

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
