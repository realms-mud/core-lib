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

    addChild("guilds/aegis-guard/forms/sword/eithagos.c",
        "guilds/aegis-guard/forms/sword/root.c");
    addChild("guilds/aegis-guard/forms/sword/nistaros.c",
        "guilds/aegis-guard/forms/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/tharcuth.c");
    addResearchElement("guilds/aegis-guard/forms/sword/diyacuth.c");

    addChild("guilds/aegis-guard/forms/sword/tharcuth.c",
        "guilds/aegis-guard/forms/sword/root.c");
    addChild("guilds/aegis-guard/forms/sword/diyacuth.c",
        "guilds/aegis-guard/forms/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{

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

}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/thar-dravn.c");
    addResearchElement("guilds/aegis-guard/forms/sword/enaidravn.c");
    addResearchElement("guilds/aegis-guard/forms/sword/nuath-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/thar-dravn.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
    addChild("guilds/aegis-guard/forms/sword/enaidravn.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
    addChild("guilds/aegis-guard/forms/sword/nuath-dravn.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/edaid-lhewig.c");
    addResearchElement("guilds/aegis-guard/forms/sword/nir-nuquerna.c");

    addChild("guilds/aegis-guard/forms/sword/edaid-lhewig.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
    addChild("guilds/aegis-guard/forms/sword/nir-nuquerna.c",
        "guilds/aegis-guard/forms/sword/caragpholg.c");
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

    addChild("guilds/aegis-guard/forms/sword/ruth-dravn.c",
        "guilds/aegis-guard/forms/sword/thar-dravn.c");
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
private void ThirtiethLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{

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
