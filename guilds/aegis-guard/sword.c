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
    addResearchElement("guilds/aegis-guard/forms/sword/celon-ai-esgal.c");

    addChild("guilds/aegis-guard/forms/sword/eithagos.c",
        "guilds/aegis-guard/forms/sword/root.c");
    addChild("guilds/aegis-guard/forms/sword/nistaros.c",
        "guilds/aegis-guard/forms/sword/root.c");
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
    addResearchElement("guilds/aegis-guard/forms/sword/laiga-utha.c");
    addResearchElement("guilds/aegis-guard/forms/sword/tharcuth.c");
    addResearchElement("guilds/aegis-guard/forms/sword/diyacuth.c");

    addChild("guilds/aegis-guard/forms/sword/laiga-utha.c",
        "guilds/aegis-guard/forms/sword/root.c");
    addChild("guilds/aegis-guard/forms/sword/tharcuth.c",
        "guilds/aegis-guard/forms/sword/root.c");
    addChild("guilds/aegis-guard/forms/sword/diyacuth.c",
        "guilds/aegis-guard/forms/sword/root.c");
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
    addResearchElement("guilds/aegis-guard/forms/sword/dravnu.c");

    addChild("guilds/aegis-guard/forms/sword/dirn-pandastan.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
    addChild("guilds/aegis-guard/forms/sword/tirnruth.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
    addChild("guilds/aegis-guard/forms/sword/glin-an-aemas.c",
        "guilds/aegis-guard/forms/sword/an-craban.c");
    addChild("guilds/aegis-guard/forms/sword/dravnu.c",
        "guilds/aegis-guard/forms/sword/eithagos.c");
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
    addResearchElement("guilds/aegis-guard/forms/sword/sa-pad.c");
    addResearchElement("guilds/aegis-guard/forms/sword/raud-angannon.c");
    addResearchElement("guilds/aegis-guard/forms/sword/alagos-tir-angannon.c");

    addChild("guilds/aegis-guard/forms/sword/sa-pad.c",
        "guilds/aegis-guard/forms/sword/laiga-utha.c");
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
    addResearchElement("guilds/aegis-guard/forms/sword/tafnenrin.c");

    addChild("guilds/aegis-guard/forms/sword/aucir.c",
        "guilds/aegis-guard/forms/sword/dravnu.c");
    addChild("guilds/aegis-guard/forms/sword/tafnenrin.c",
        "guilds/aegis-guard/forms/sword/an-vund.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/raica-dravn.c");
    addResearchElement("guilds/aegis-guard/forms/sword/lilt-an-gurth.c");

    addChild("guilds/aegis-guard/forms/sword/raica-dravn.c",
        "guilds/aegis-guard/forms/sword/enaidravn.c");
    addChild("guilds/aegis-guard/forms/sword/lilt-an-gurth.c",
        "guilds/aegis-guard/forms/sword/sa-pad.c");
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
    addResearchElement("guilds/aegis-guard/forms/sword/thar-legol.c");

    addChild("guilds/aegis-guard/forms/sword/lelyan-isilme.c",
        "guilds/aegis-guard/forms/sword/nistaros.c");
    addChild("guilds/aegis-guard/forms/sword/thar-legol.c",
        "guilds/aegis-guard/forms/sword/lilt-an-gurth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/seidia-dyr.c");
    addResearchElement("guilds/aegis-guard/forms/sword/lanna-dravn.c");

    addChild("guilds/aegis-guard/forms/sword/seidia-dyr.c",
        "guilds/aegis-guard/forms/sword/lilt-an-gurth.c");
    addChild("guilds/aegis-guard/forms/sword/lanna-dravn.c",
        "guilds/aegis-guard/forms/sword/thar-dravn.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/pirin-tir.c");
    addResearchElement("guilds/aegis-guard/forms/sword/legol-imrath.c");

    addChild("guilds/aegis-guard/forms/sword/pirin-tir.c",
        "guilds/aegis-guard/forms/sword/lilt-an-gurth.c");
    addChild("guilds/aegis-guard/forms/sword/legol-imrath.c",
        "guilds/aegis-guard/forms/sword/lilt-an-gurth.c");
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
    addResearchElement("guilds/aegis-guard/forms/sword/edluc.c");
    addResearchElement("guilds/aegis-guard/forms/sword/gwaedrhen.c");

    addChild("guilds/aegis-guard/forms/sword/edluc.c",
        "guilds/aegis-guard/forms/sword/pirin-tir.c");
    addChild("guilds/aegis-guard/forms/sword/gwaedrhen.c",
        "guilds/aegis-guard/forms/sword/seidia-dyr.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/dagnir-rhinc.c");

    addChild("guilds/aegis-guard/forms/sword/dagnir-rhinc.c",
        "guilds/aegis-guard/forms/sword/lilt-an-gurth.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/pirin-maed-tir.c");

    addChild("guilds/aegis-guard/forms/sword/pirin-maed-tir.c",
        "guilds/aegis-guard/forms/sword/pirin-tir.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("guilds/aegis-guard/forms/sword/nista-ai-mab.c");

    addChild("guilds/aegis-guard/forms/sword/nista-ai-mab.c",
        "guilds/aegis-guard/forms/sword/pirin-tir.c");
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
        Name("Pengolod ai Megil");
        Description("");
        Source("Aegis Guard");
        addResearchElement("guilds/aegis-guard/forms/sword/root.c");
        TreeRoot("guilds/aegis-guard/forms/sword/root.c");

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
