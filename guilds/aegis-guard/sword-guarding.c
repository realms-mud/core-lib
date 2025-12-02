//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c",
        "/guilds/aegis-guard/forms/sword-guarding/guarding-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/an-vund.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/an-aras.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/an-lobraidywe.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/gwisten.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/an-vund.c",
        "/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/an-aras.c",
        "/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/an-lobraidywe.c",
        "/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/gwisten.c",
        "/guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/an-craban.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/an-rin.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/uva-tirith.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/an-craban.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-vund.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/an-rin.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-vund.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/uva-tirith.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-vund.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/dirn-pandastan.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/tirnruth.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/glin-an-aemas.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/dirn-pandastan.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-craban.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/tirnruth.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-craban.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/glin-an-aemas.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-craban.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/an-foph.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/angannon.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/an-foph.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-craban.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/angannon.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-craban.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/raud-angannon.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/alagos-tir-angannon.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/raud-angannon.c",
        "/guilds/aegis-guard/forms/sword-guarding/angannon.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/alagos-tir-angannon.c",
        "/guilds/aegis-guard/forms/sword-guarding/angannon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/glingamath.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/sathataen.c");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/caragpholg.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/glingamath.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-foph.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/sathataen.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-foph.c");
    addChild("/guilds/aegis-guard/forms/sword-guarding/caragpholg.c",
        "/guilds/aegis-guard/forms/sword-guarding/angannon.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/nir-nuquerna.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/nir-nuquerna.c",
        "/guilds/aegis-guard/forms/sword-guarding/caragpholg.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/tafnenrin.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/tafnenrin.c",
        "/guilds/aegis-guard/forms/sword-guarding/an-vund.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/mithrannon.c");

    addChild("/guilds/aegis-guard/forms/sword-guarding/mithrannon.c",
        "/guilds/aegis-guard/forms/sword-guarding/angannon.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tirith ai Megil");
    Description("");
    Source("Aegis Guard");
    addResearchElement("/guilds/aegis-guard/forms/sword-guarding/guarding-root.c");
    TreeRoot("/guilds/aegis-guard/forms/sword-guarding/guarding-root.c");

    FirstLevel();
    SecondLevel();
    FourthLevel();
    FifthLevel();
    SixthLevel();
    SeventhLevel();
    EighthLevel();
    TenthLevel();
    TwelfthLevel();
    ThirtyFirstLevel();
}
