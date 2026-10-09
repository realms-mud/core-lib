//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/mana-shield.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/arcane-shield.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/fire-resistance.c");

    addChild("/guilds/drambor-edlothiad/defense/mana-shield.c",
        "/guilds/drambor-edlothiad/defense/root.c");
    addChild("/guilds/drambor-edlothiad/defense/arcane-shield.c",
        "/guilds/drambor-edlothiad/defense/root.c");
    addChild("/guilds/drambor-edlothiad/defense/fire-resistance.c",
        "/guilds/drambor-edlothiad/defense/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/cold-resistance.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/electricity-resistance.c");

    addChild("/guilds/drambor-edlothiad/defense/cold-resistance.c",
        "/guilds/drambor-edlothiad/defense/fire-resistance.c");
    addChild("/guilds/drambor-edlothiad/defense/electricity-resistance.c",
        "/guilds/drambor-edlothiad/defense/fire-resistance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/acid-resistance.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/aegis-of-the-ancients.c");

    addChild("/guilds/drambor-edlothiad/defense/acid-resistance.c",
        "/guilds/drambor-edlothiad/defense/cold-resistance.c");
    addChild("/guilds/drambor-edlothiad/defense/aegis-of-the-ancients.c",
        "/guilds/drambor-edlothiad/defense/arcane-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/spell-ward.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/energy-resistance.c");

    addChild("/guilds/drambor-edlothiad/defense/spell-ward.c",
        "/guilds/drambor-edlothiad/defense/mana-shield.c");
    addChild("/guilds/drambor-edlothiad/defense/energy-resistance.c",
        "/guilds/drambor-edlothiad/defense/electricity-resistance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/elven-ward-mastery.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/magical-resistance.c");

    addChild("/guilds/drambor-edlothiad/defense/elven-ward-mastery.c",
        "/guilds/drambor-edlothiad/defense/spell-ward.c");
    addChild("/guilds/drambor-edlothiad/defense/magical-resistance.c",
        "/guilds/drambor-edlothiad/defense/energy-resistance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/spell-resistance.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/ward-expertise.c");

    addChild("/guilds/drambor-edlothiad/defense/spell-resistance.c",
        "/guilds/drambor-edlothiad/defense/magical-resistance.c");
    addChild("/guilds/drambor-edlothiad/defense/ward-expertise.c",
        "/guilds/drambor-edlothiad/defense/elven-ward-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/resilient-aura.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/mystic-resilience.c");

    addChild("/guilds/drambor-edlothiad/defense/resilient-aura.c",
        "/guilds/drambor-edlothiad/defense/aegis-of-the-ancients.c");
    addChild("/guilds/drambor-edlothiad/defense/mystic-resilience.c",
        "/guilds/drambor-edlothiad/defense/spell-resistance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/mystic-barrier.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/ward-mastery.c");

    addChild("/guilds/drambor-edlothiad/defense/mystic-barrier.c",
        "/guilds/drambor-edlothiad/defense/spell-ward.c");
    addChild("/guilds/drambor-edlothiad/defense/ward-mastery.c",
        "/guilds/drambor-edlothiad/defense/ward-expertise.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/arcane-absorption.c");

    addChild("/guilds/drambor-edlothiad/defense/arcane-absorption.c",
        "/guilds/drambor-edlothiad/defense/mystic-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/elven-fortification.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/ward-mastery-knowledge.c");

    addChild("/guilds/drambor-edlothiad/defense/elven-fortification.c",
        "/guilds/drambor-edlothiad/defense/resilient-aura.c");
    addChild("/guilds/drambor-edlothiad/defense/ward-mastery-knowledge.c",
        "/guilds/drambor-edlothiad/defense/ward-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/fortified-will.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/impenetrable-will.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/arcane-barrier.c");

    addChild("/guilds/drambor-edlothiad/defense/fortified-will.c",
        "/guilds/drambor-edlothiad/defense/arcane-absorption.c");
    addChild("/guilds/drambor-edlothiad/defense/impenetrable-will.c",
        "/guilds/drambor-edlothiad/defense/mystic-resilience.c");
    addChild("/guilds/drambor-edlothiad/defense/arcane-barrier.c",
        "/guilds/drambor-edlothiad/defense/arcane-absorption.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/aegis-of-resolve.c");

    addChild("/guilds/drambor-edlothiad/defense/aegis-of-resolve.c",
        "/guilds/drambor-edlothiad/defense/arcane-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/arcane-aegis.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/ward-amplification.c");

    addChild("/guilds/drambor-edlothiad/defense/arcane-aegis.c",
        "/guilds/drambor-edlothiad/defense/mystic-barrier.c");
    addChild("/guilds/drambor-edlothiad/defense/ward-amplification.c",
        "/guilds/drambor-edlothiad/defense/ward-mastery-knowledge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/elven-bulwark.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/arcane-barrier-mastery.c");

    addChild("/guilds/drambor-edlothiad/defense/elven-bulwark.c",
        "/guilds/drambor-edlothiad/defense/arcane-aegis.c");
    addChild("/guilds/drambor-edlothiad/defense/arcane-barrier-mastery.c",
        "/guilds/drambor-edlothiad/defense/ward-amplification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/mystic-fortification.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/ward-supremacy.c");

    addChild("/guilds/drambor-edlothiad/defense/mystic-fortification.c",
        "/guilds/drambor-edlothiad/defense/elven-bulwark.c");
    addChild("/guilds/drambor-edlothiad/defense/ward-supremacy.c",
        "/guilds/drambor-edlothiad/defense/arcane-barrier-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/supreme-resistance.c");

    addChild("/guilds/drambor-edlothiad/defense/supreme-resistance.c",
        "/guilds/drambor-edlothiad/defense/impenetrable-will.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/invulnerability.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/divine-aegis.c");

    addChild("/guilds/drambor-edlothiad/defense/invulnerability.c",
        "/guilds/drambor-edlothiad/defense/arcane-aegis.c");
    addChild("/guilds/drambor-edlothiad/defense/divine-aegis.c",
        "/guilds/drambor-edlothiad/defense/mystic-fortification.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/greater-ward.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/invulnerability-mastery.c");

    addChild("/guilds/drambor-edlothiad/defense/greater-ward.c",
        "/guilds/drambor-edlothiad/defense/invulnerability.c");
    addChild("/guilds/drambor-edlothiad/defense/invulnerability-mastery.c",
        "/guilds/drambor-edlothiad/defense/invulnerability.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/shield-of-ages.c");

    addChild("/guilds/drambor-edlothiad/defense/shield-of-ages.c",
        "/guilds/drambor-edlothiad/defense/divine-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/supreme-aegis.c");

    addChild("/guilds/drambor-edlothiad/defense/supreme-aegis.c",
        "/guilds/drambor-edlothiad/defense/greater-ward.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/absolute-protection.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/transcendent-defense.c");

    addChild("/guilds/drambor-edlothiad/defense/absolute-protection.c",
        "/guilds/drambor-edlothiad/defense/shield-of-ages.c");
    addChild("/guilds/drambor-edlothiad/defense/transcendent-defense.c",
        "/guilds/drambor-edlothiad/defense/supreme-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/immortal-ward.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/eternal-protection.c");

    addChild("/guilds/drambor-edlothiad/defense/immortal-ward.c",
        "/guilds/drambor-edlothiad/defense/supreme-aegis.c");
    addChild("/guilds/drambor-edlothiad/defense/eternal-protection.c",
        "/guilds/drambor-edlothiad/defense/absolute-protection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/eternal-aegis.c");
    addResearchElement("/guilds/drambor-edlothiad/defense/immortal-aegis.c");

    addChild("/guilds/drambor-edlothiad/defense/eternal-aegis.c",
        "/guilds/drambor-edlothiad/defense/immortal-ward.c");
    addChild("/guilds/drambor-edlothiad/defense/immortal-aegis.c",
        "/guilds/drambor-edlothiad/defense/eternal-protection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventyLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/defense/avatar-of-protection.c");

    addChild("/guilds/drambor-edlothiad/defense/avatar-of-protection.c",
        "/guilds/drambor-edlothiad/defense/eternal-aegis.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Mystical Defense");
    Description("This research tree provides magical defensive techniques, "
        "including wards, shields, and protective enchantments.");
    Source("Drambor Edlothiad");
    addResearchElement("/guilds/drambor-edlothiad/defense/root.c");
    TreeRoot("/guilds/drambor-edlothiad/defense/root.c");

    ThirdLevel();
    FifthLevel();
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
    ThirtyFirstLevel();
    ThirtyFifthLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FortyNinthLevel();
    FiftyFirstLevel();
    FiftyFifthLevel();
    FiftyNinthLevel();
    SixtyFifthLevel();
    SeventyLevel();
}
