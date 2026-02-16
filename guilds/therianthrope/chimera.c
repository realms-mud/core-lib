//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/predatory-precision.c");
    addResearchElement("/guilds/therianthrope/chimera/composite-hide.c");

    addChild("/guilds/therianthrope/chimera/predatory-precision.c",
        "/guilds/therianthrope/chimera/chimera-root.c");
    addChild("/guilds/therianthrope/chimera/composite-hide.c",
        "/guilds/therianthrope/chimera/chimera-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/rending-claws.c");
    addResearchElement("/guilds/therianthrope/chimera/chimeric-resilience.c");

    addChild("/guilds/therianthrope/chimera/rending-claws.c",
        "/guilds/therianthrope/chimera/predatory-precision.c");
    addChild("/guilds/therianthrope/chimera/chimeric-resilience.c",
        "/guilds/therianthrope/chimera/composite-hide.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/burning-blood.c");
    addResearchElement("/guilds/therianthrope/chimera/gore.c");

    addChild("/guilds/therianthrope/chimera/burning-blood.c",
        "/guilds/therianthrope/chimera/rending-claws.c");
    addChild("/guilds/therianthrope/chimera/gore.c",
        "/guilds/therianthrope/chimera/chimeric-resilience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/lionheart.c");
    addResearchElement("/guilds/therianthrope/chimera/goats-tenacity.c");

    addChild("/guilds/therianthrope/chimera/lionheart.c",
        "/guilds/therianthrope/chimera/burning-blood.c");
    addChild("/guilds/therianthrope/chimera/goats-tenacity.c",
        "/guilds/therianthrope/chimera/chimeric-resilience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/fire-breath.c");
    addResearchElement("/guilds/therianthrope/chimera/feral-efficiency.c");

    addChild("/guilds/therianthrope/chimera/fire-breath.c",
        "/guilds/therianthrope/chimera/lionheart.c");
    addChild("/guilds/therianthrope/chimera/feral-efficiency.c",
        "/guilds/therianthrope/chimera/goats-tenacity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/chimeric-mastery.c");
    addResearchElement("/guilds/therianthrope/chimera/bestial-rage.c");

    addChild("/guilds/therianthrope/chimera/chimeric-mastery.c",
        "/guilds/therianthrope/chimera/fire-breath.c");
    addChild("/guilds/therianthrope/chimera/bestial-rage.c",
        "/guilds/therianthrope/chimera/goats-tenacity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/searing-claws.c");
    addResearchElement("/guilds/therianthrope/chimera/feral-celerity.c");

    addChild("/guilds/therianthrope/chimera/searing-claws.c",
        "/guilds/therianthrope/chimera/chimeric-mastery.c");
    addChild("/guilds/therianthrope/chimera/feral-celerity.c",
        "/guilds/therianthrope/chimera/feral-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/primal-chimera.c");
    addResearchElement("/guilds/therianthrope/chimera/flame-ward.c");

    addChild("/guilds/therianthrope/chimera/primal-chimera.c",
        "/guilds/therianthrope/chimera/searing-claws.c");
    addChild("/guilds/therianthrope/chimera/flame-ward.c",
        "/guilds/therianthrope/chimera/bestial-rage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/blazing-mane.c");

    addChild("/guilds/therianthrope/chimera/blazing-mane.c",
        "/guilds/therianthrope/chimera/primal-chimera.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/chimeric-apotheosis.c");
    addResearchElement("/guilds/therianthrope/chimera/chimeric-rampage.c");

    addChild("/guilds/therianthrope/chimera/chimeric-apotheosis.c",
        "/guilds/therianthrope/chimera/blazing-mane.c");
    addChild("/guilds/therianthrope/chimera/chimeric-rampage.c",
        "/guilds/therianthrope/chimera/flame-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/three-headed-assault.c");
    addResearchElement("/guilds/therianthrope/chimera/hardened-scales.c");

    addChild("/guilds/therianthrope/chimera/three-headed-assault.c",
        "/guilds/therianthrope/chimera/chimeric-apotheosis.c");
    addChild("/guilds/therianthrope/chimera/hardened-scales.c",
        "/guilds/therianthrope/chimera/chimeric-rampage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/tri-form-fury.c");
    addResearchElement("/guilds/therianthrope/chimera/inferno.c");

    addChild("/guilds/therianthrope/chimera/tri-form-fury.c",
        "/guilds/therianthrope/chimera/three-headed-assault.c");
    addChild("/guilds/therianthrope/chimera/inferno.c",
        "/guilds/therianthrope/chimera/flame-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/ember-heart.c");
    addResearchElement("/guilds/therianthrope/chimera/ashen-ward.c");

    addChild("/guilds/therianthrope/chimera/ember-heart.c",
        "/guilds/therianthrope/chimera/tri-form-fury.c");
    addChild("/guilds/therianthrope/chimera/ashen-ward.c",
        "/guilds/therianthrope/chimera/inferno.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/chimera-tyrant.c");
    addResearchElement("/guilds/therianthrope/chimera/molten-core.c");

    addChild("/guilds/therianthrope/chimera/chimera-tyrant.c",
        "/guilds/therianthrope/chimera/ember-heart.c");
    addChild("/guilds/therianthrope/chimera/molten-core.c",
        "/guilds/therianthrope/chimera/ashen-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/eternal-chimera.c");

    addChild("/guilds/therianthrope/chimera/eternal-chimera.c",
        "/guilds/therianthrope/chimera/chimera-tyrant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/chimera-ascendant.c");

    addChild("/guilds/therianthrope/chimera/chimera-ascendant.c",
        "/guilds/therianthrope/chimera/eternal-chimera.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/chimera/mythic-chimera.c");

    addChild("/guilds/therianthrope/chimera/mythic-chimera.c",
        "/guilds/therianthrope/chimera/chimera-ascendant.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Chimera Form");
    Description("This research tree provides knowledge of transforming into "
        "a fearsome chimera. The chimera form excels at savage melee combat "
        "and fire-based attacks. Progressive mastery unlocks devastating "
        "rending strikes, fiery breath, and eventually the power of the "
        "mythic chimera itself.");
    Source("therianthrope");
    addResearchElement("/guilds/therianthrope/chimera/chimera-root.c");
    TreeRoot("/guilds/therianthrope/chimera/chimera-root.c");

    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FortyNinthLevel();
    FiftyFifthLevel();
    SixtyFirstLevel();
    SixtySeventhLevel();
}
