//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/minor-bladesong.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/defensive-harmonics.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/bladesong-initiation.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/minor-bladesong.c",
        "/guilds/drambor-edlothiad/bladesinger/root.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/defensive-harmonics.c",
        "/guilds/drambor-edlothiad/bladesinger/root.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/bladesong-initiation.c",
        "/guilds/drambor-edlothiad/bladesinger/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/bladesong-stance.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/warding-song.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/elven-footwork.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/bladesong-stance.c",
        "/guilds/drambor-edlothiad/bladesinger/minor-bladesong.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/warding-song.c",
        "/guilds/drambor-edlothiad/bladesinger/defensive-harmonics.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/elven-footwork.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesong-initiation.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/melodic-flow.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/melodic-flow.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesong-stance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/bladesong-of-valor.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/shield-of-song.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/melodic-strikes.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/bladesong-of-valor.c",
        "/guilds/drambor-edlothiad/bladesinger/melodic-flow.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/shield-of-song.c",
        "/guilds/drambor-edlothiad/bladesinger/warding-song.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/melodic-strikes.c",
        "/guilds/drambor-edlothiad/bladesinger/melodic-flow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/elven-war-dance.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/resonant-ward.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/harmonic-flow.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/elven-war-dance.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesong-of-valor.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/resonant-ward.c",
        "/guilds/drambor-edlothiad/bladesinger/shield-of-song.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/harmonic-flow.c",
        "/guilds/drambor-edlothiad/bladesinger/shield-of-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/harmonic-precision.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/bladesinger-elven-grace.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/counter-melody.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/harmonic-precision.c",
        "/guilds/drambor-edlothiad/bladesinger/elven-war-dance.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/bladesinger-elven-grace.c",
        "/guilds/drambor-edlothiad/bladesinger/resonant-ward.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/counter-melody.c",
        "/guilds/drambor-edlothiad/bladesinger/harmonic-flow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/greater-bladesong.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/greater-bladesong.c",
        "/guilds/drambor-edlothiad/bladesinger/harmonic-precision.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/song-of-steel.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/fortress-of-song.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/harmonic-blade.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/song-of-steel.c",
        "/guilds/drambor-edlothiad/bladesinger/greater-bladesong.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/fortress-of-song.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesinger-elven-grace.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/harmonic-blade.c",
        "/guilds/drambor-edlothiad/bladesinger/song-of-steel.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/rhythm-of-battle.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/dissonant-strike.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/rhythm-of-battle.c",
        "/guilds/drambor-edlothiad/bladesinger/song-of-steel.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/dissonant-strike.c",
        "/guilds/drambor-edlothiad/bladesinger/harmonic-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/bladesong-of-the-ancients.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/harmonic-barrier.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/bladesong-of-the-ancients.c",
        "/guilds/drambor-edlothiad/bladesinger/rhythm-of-battle.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/harmonic-barrier.c",
        "/guilds/drambor-edlothiad/bladesinger/fortress-of-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/bladesong-mastery.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/bladesong-mastery.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesong-of-the-ancients.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/song-of-warding.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/crescendo.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/song-of-warding.c",
        "/guilds/drambor-edlothiad/bladesinger/harmonic-barrier.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/crescendo.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesong-of-the-ancients.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/transcendent-bladesong.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/transcendent-bladesong.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesong-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/fortissimo.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/fortissimo.c",
        "/guilds/drambor-edlothiad/bladesinger/crescendo.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/voice-of-the-blade.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/voice-of-the-blade.c",
        "/guilds/drambor-edlothiad/bladesinger/transcendent-bladesong.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/invincible-harmony.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/tempo-of-war.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/invincible-harmony.c",
        "/guilds/drambor-edlothiad/bladesinger/song-of-warding.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/tempo-of-war.c",
        "/guilds/drambor-edlothiad/bladesinger/fortissimo.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/eternal-melody.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/eternal-melody.c",
        "/guilds/drambor-edlothiad/bladesinger/voice-of-the-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/symphonic-assault.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/symphonic-assault.c",
        "/guilds/drambor-edlothiad/bladesinger/tempo-of-war.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/supreme-bladesong.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/unbreakable-song.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/supreme-bladesong.c",
        "/guilds/drambor-edlothiad/bladesinger/eternal-melody.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/unbreakable-song.c",
        "/guilds/drambor-edlothiad/bladesinger/invincible-harmony.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/maestro-of-war.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/maestro-of-war.c",
        "/guilds/drambor-edlothiad/bladesinger/symphonic-assault.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/blade-singers-perfection.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/blade-singers-perfection.c",
        "/guilds/drambor-edlothiad/bladesinger/supreme-bladesong.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/song-of-the-stars.c");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/eternal-ward.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/song-of-the-stars.c",
        "/guilds/drambor-edlothiad/bladesinger/blade-singers-perfection.c");
    addChild("/guilds/drambor-edlothiad/bladesinger/eternal-ward.c",
        "/guilds/drambor-edlothiad/bladesinger/unbreakable-song.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/celestial-bladesong.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/celestial-bladesong.c",
        "/guilds/drambor-edlothiad/bladesinger/song-of-the-stars.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/starlight-dancer.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/starlight-dancer.c",
        "/guilds/drambor-edlothiad/bladesinger/celestial-bladesong.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/legendary-blade-singer.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/legendary-blade-singer.c",
        "/guilds/drambor-edlothiad/bladesinger/starlight-dancer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/bladesong-of-creation.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/bladesong-of-creation.c",
        "/guilds/drambor-edlothiad/bladesinger/legendary-blade-singer.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventyLevel()
{
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/avatar-of-the-bladesong.c");

    addChild("/guilds/drambor-edlothiad/bladesinger/avatar-of-the-bladesong.c",
        "/guilds/drambor-edlothiad/bladesinger/bladesong-of-creation.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("High Blade Singer");
    Description("This research tree represents the ancient elven art of "
        "bladesinging - the fusion of arcane melody with lethal swordplay. "
        "High Blade Singers are the pinnacle of this tradition, weaving "
        "song and steel into a deadly dance.");
    Source("Drambor Edlothiad");
    addResearchElement("/guilds/drambor-edlothiad/bladesinger/root.c");
    TreeRoot("/guilds/drambor-edlothiad/bladesinger/root.c");

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
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortyNinthLevel();
    FiftyThirdLevel();
    FiftySeventhLevel();
    SixtyFirstLevel();
    SixtyFifthLevel();
    SeventyLevel();
}
