//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/celon-ai-esgal.c");

    addChild("guilds/aegis-guard/forms/sword/celon-ai-esgal.c",
        "guilds/aegis-guard/forms/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/an-vund.c");
    addResearchElement("guilds/aegis-guard/forms/sword/an-aras.c");
    addResearchElement("guilds/aegis-guard/forms/sword/an-lobraidywe.c");
    addResearchElement("guilds/aegis-guard/forms/sword/gwisten.c");

    addChild("guilds/aegis-guard/forms/sword/an-vund.c",
        "guilds/aegis-guard/forms/sword/celon-ai-esgal.c");
    addChild("guilds/aegis-guard/forms/sword/an-aras.c",
        "guilds/aegis-guard/forms/sword/celon-ai-esgal.c");
    addChild("guilds/aegis-guard/forms/sword/an-lobraidywe.c",
        "guilds/aegis-guard/forms/sword/celon-ai-esgal.c");
    addChild("guilds/aegis-guard/forms/sword/gwisten.c",
        "guilds/aegis-guard/forms/sword/celon-ai-esgal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/an-craban.c");
    addResearchElement("guilds/aegis-guard/forms/sword/an-rin.c");
    addResearchElement("guilds/aegis-guard/forms/sword/uva-tirith.c");

    addChild("guilds/aegis-guard/forms/sword/an-craban.c",
        "guilds/aegis-guard/forms/sword/an-vund.c");
    addChild("guilds/aegis-guard/forms/sword/an-rin.c",
        "guilds/aegis-guard/forms/sword/an-vund.c");
    addChild("guilds/aegis-guard/forms/sword/uva-tirith.c",
        "guilds/aegis-guard/forms/sword/an-vund.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/dirn-pandastan.c");
    addResearchElement("guilds/aegis-guard/forms/sword/tirnruth.c");
    addResearchElement("guilds/aegis-guard/forms/sword/glin-an-aemas.c");

    addChild("guilds/aegis-guard/forms/sword/dirn-pandastan.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
    addChild("guilds/aegis-guard/forms/sword/tirnruth.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
    addChild("guilds/aegis-guard/forms/sword/glin-an-aemas.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/an-foph.c");
    addResearchElement("guilds/aegis-guard/forms/sword/angannon.c");

    addChild("guilds/aegis-guard/forms/sword/an-foph.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
    addChild("guilds/aegis-guard/forms/sword/angannon.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/raud-angannon.c");
    addResearchElement("guilds/aegis-guard/forms/sword/alagos-tir-angannon.c");

    addChild("guilds/aegis-guard/forms/sword/raud-angannon.c",
        "guilds/aegis-guard/forms/sword/angannon.c");
    addChild("guilds/aegis-guard/forms/sword/alagos-tir-angannon.c",
        "guilds/aegis-guard/forms/sword/angannon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/glingamath.c");
    addResearchElement("guilds/aegis-guard/forms/sword/sathataen.c");
    addResearchElement("guilds/aegis-guard/forms/sword/caragpholg.c");

    addChild("guilds/aegis-guard/forms/sword/glingamath.c",
        "guilds/aegis-guard/forms/sword/an-foph.c");
    addChild("guilds/aegis-guard/forms/sword/sathataen.c",
        "guilds/aegis-guard/forms/sword/an-foph.c");
    addChild("guilds/aegis-guard/forms/sword/caragpholg.c",
        "guilds/aegis-guard/forms/sword/angannon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/nir-nuquerna.c");

    addChild("guilds/aegis-guard/forms/sword/nir-nuquerna.c",
        "guilds/aegis-guard/forms/sword/caragpholg.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/tafnenrin.c");

    addChild("guilds/aegis-guard/forms/sword/tafnenrin.c",
        "guilds/aegis-guard/forms/sword/an-vund.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FourteenLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
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
private void TwentiethLevel()
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
private void ThirtiethLevel()
{

}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/mithrannon.c");

    addChild("guilds/aegis-guard/forms/sword/mithrannon.c",
        "guilds/aegis-guard/forms/sword/angannon.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Tirith ai Megil");
        Description("");
        Source("Aegis Guard");
        addResearchElement("guilds/aegis-guard/forms/sword/guarding-root.c");
        TreeRoot("guilds/aegis-guard/forms/sword/guarding-root.c");

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
