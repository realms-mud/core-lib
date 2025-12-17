//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/shadow-self.c");

    addChild("/guilds/oneiromancer/nightmare-persona/shadow-self.c",
        "/guilds/oneiromancer/nightmare-persona/persona-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/dread-presence.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/fearsome-visage.c");

    addChild("/guilds/oneiromancer/nightmare-persona/dread-presence.c",
        "/guilds/oneiromancer/nightmare-persona/shadow-self.c");
    addChild("/guilds/oneiromancer/nightmare-persona/fearsome-visage.c",
        "/guilds/oneiromancer/nightmare-persona/shadow-self.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/terror-aura.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/dream-walker.c");

    addChild("/guilds/oneiromancer/nightmare-persona/terror-aura.c",
        "/guilds/oneiromancer/nightmare-persona/dread-presence.c");
    addChild("/guilds/oneiromancer/nightmare-persona/dream-walker.c",
        "/guilds/oneiromancer/nightmare-persona/fearsome-visage.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/mind-shield.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/phantom-form.c");

    addChild("/guilds/oneiromancer/nightmare-persona/mind-shield.c",
        "/guilds/oneiromancer/nightmare-persona/terror-aura.c");
    addChild("/guilds/oneiromancer/nightmare-persona/phantom-form.c",
        "/guilds/oneiromancer/nightmare-persona/dream-walker.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/psychic-predator.c");

    addChild("/guilds/oneiromancer/nightmare-persona/psychic-predator.c",
        "/guilds/oneiromancer/nightmare-persona/mind-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/haunting-presence.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/ethereal-shroud.c");

    addChild("/guilds/oneiromancer/nightmare-persona/haunting-presence.c",
        "/guilds/oneiromancer/nightmare-persona/psychic-predator.c");
    addChild("/guilds/oneiromancer/nightmare-persona/ethereal-shroud.c",
        "/guilds/oneiromancer/nightmare-persona/phantom-form.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/consuming-darkness.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/dream-devourer.c");

    addChild("/guilds/oneiromancer/nightmare-persona/consuming-darkness.c",
        "/guilds/oneiromancer/nightmare-persona/haunting-presence.c");
    addChild("/guilds/oneiromancer/nightmare-persona/dream-devourer.c",
        "/guilds/oneiromancer/nightmare-persona/ethereal-shroud.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/lord-of-fears.c");

    addChild("/guilds/oneiromancer/nightmare-persona/lord-of-fears.c",
        "/guilds/oneiromancer/nightmare-persona/consuming-darkness.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/mind-fortress.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/terror-incarnate.c");

    addChild("/guilds/oneiromancer/nightmare-persona/mind-fortress.c",
        "/guilds/oneiromancer/nightmare-persona/lord-of-fears.c");
    addChild("/guilds/oneiromancer/nightmare-persona/terror-incarnate.c",
        "/guilds/oneiromancer/nightmare-persona/dream-devourer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/avatar-of-nightmares.c");

    addChild("/guilds/oneiromancer/nightmare-persona/avatar-of-nightmares.c",
        "/guilds/oneiromancer/nightmare-persona/mind-fortress.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/dream-tyrant.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/nightmare-apotheosis.c");

    addChild("/guilds/oneiromancer/nightmare-persona/dream-tyrant.c",
        "/guilds/oneiromancer/nightmare-persona/avatar-of-nightmares.c");
    addChild("/guilds/oneiromancer/nightmare-persona/nightmare-apotheosis.c",
        "/guilds/oneiromancer/nightmare-persona/terror-incarnate.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/supreme-nightmare.c");

    addChild("/guilds/oneiromancer/nightmare-persona/supreme-nightmare.c",
        "/guilds/oneiromancer/nightmare-persona/dream-tyrant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/abyssal-mind.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/eternal-dread.c");

    addChild("/guilds/oneiromancer/nightmare-persona/abyssal-mind.c",
        "/guilds/oneiromancer/nightmare-persona/supreme-nightmare.c");
    addChild("/guilds/oneiromancer/nightmare-persona/eternal-dread.c",
        "/guilds/oneiromancer/nightmare-persona/nightmare-apotheosis.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/void-touched.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/unending-terror.c");

    addChild("/guilds/oneiromancer/nightmare-persona/void-touched.c",
        "/guilds/oneiromancer/nightmare-persona/abyssal-mind.c");
    addChild("/guilds/oneiromancer/nightmare-persona/unending-terror.c",
        "/guilds/oneiromancer/nightmare-persona/eternal-dread.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/dream-sovereign.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/immortal-nightmare.c");

    addChild("/guilds/oneiromancer/nightmare-persona/dream-sovereign.c",
        "/guilds/oneiromancer/nightmare-persona/void-touched.c");
    addChild("/guilds/oneiromancer/nightmare-persona/immortal-nightmare.c",
        "/guilds/oneiromancer/nightmare-persona/unending-terror.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/primordial-fear.c");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/deathless-horror.c");

    addChild("/guilds/oneiromancer/nightmare-persona/primordial-fear.c",
        "/guilds/oneiromancer/nightmare-persona/dream-sovereign.c");
    addChild("/guilds/oneiromancer/nightmare-persona/deathless-horror.c",
        "/guilds/oneiromancer/nightmare-persona/immortal-nightmare.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/oneiromancer/nightmare-persona/nightmare-eternal.c");

    addChild("/guilds/oneiromancer/nightmare-persona/nightmare-eternal.c",
        "/guilds/oneiromancer/nightmare-persona/primordial-fear.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Nightmare Persona");
    Description("This research tree provides knowledge of adopting nightmare "
        "personas - dark identities drawn from the realm of dreams. These "
        "personas grant passive abilities that enhance the oneiromancers "
        "power, protect their mind, and instill fear in their enemies.");
    Source("oneiromancer");
    addResearchElement("/guilds/oneiromancer/nightmare-persona/persona-root.c");
    TreeRoot("/guilds/oneiromancer/nightmare-persona/persona-root.c");

    FifthLevel();
    NinthLevel();
    ThirteenthLevel();
    SeventeenthLevel();
    TwentyFirstLevel();
    TwentyFifthLevel();
    TwentyNinthLevel();
    ThirtyThirdLevel();
    ThirtySeventhLevel();
    FortyFirstLevel();
    FortyFifthLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
    FiftySeventhLevel();
    SixtyFirstLevel();
    SixtyFifthLevel();
    SixtySeventhLevel();
}
