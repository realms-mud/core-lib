//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/inner-spark.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/inner-spark.c",
        "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/ember-blood.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/heat-resistance.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/ember-blood.c",
        "/guilds/disciple-of-ferianth/flame-conduit/inner-spark.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/heat-resistance.c",
        "/guilds/disciple-of-ferianth/flame-conduit/inner-spark.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    // Form-only active ability: Flame Burst
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/flame-burst.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/flame-burst.c",
        "/guilds/disciple-of-ferianth/flame-conduit/ember-blood.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/burning-aura.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/smoldering-skin.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/burning-aura.c",
        "/guilds/disciple-of-ferianth/flame-conduit/ember-blood.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/smoldering-skin.c",
        "/guilds/disciple-of-ferianth/flame-conduit/heat-resistance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    // Form-only passive: Cinder Step (movement bonus while in form)
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/cinder-step.c");
    // Knowledge modifier: Inner Fire Mastery
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/inner-fire-mastery.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/cinder-step.c",
        "/guilds/disciple-of-ferianth/flame-conduit/burning-aura.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/inner-fire-mastery.c",
        "/guilds/disciple-of-ferianth/flame-conduit/flame-burst.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/blazing-soul.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/fire-immunity.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/blazing-soul.c",
        "/guilds/disciple-of-ferianth/flame-conduit/burning-aura.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/fire-immunity.c",
        "/guilds/disciple-of-ferianth/flame-conduit/smoldering-skin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    // Form-only active ability: Immolating Grasp
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/immolating-grasp.c");
    // Knowledge modifier: Conduit Efficiency
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/conduit-efficiency.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/immolating-grasp.c",
        "/guilds/disciple-of-ferianth/flame-conduit/blazing-soul.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/conduit-efficiency.c",
        "/guilds/disciple-of-ferianth/flame-conduit/inner-fire-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/heart-of-cinders.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/heart-of-cinders.c",
        "/guilds/disciple-of-ferianth/flame-conduit/blazing-soul.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    // Form-only passive: Thermal Absorption (heal from fire damage while in form)
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/thermal-absorption.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/thermal-absorption.c",
        "/guilds/disciple-of-ferianth/flame-conduit/fire-immunity.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/infernal-veins.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/radiant-presence.c");
    // Knowledge modifier: Rapid Combustion
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/rapid-combustion.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/infernal-veins.c",
        "/guilds/disciple-of-ferianth/flame-conduit/heart-of-cinders.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/radiant-presence.c",
        "/guilds/disciple-of-ferianth/flame-conduit/fire-immunity.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/rapid-combustion.c",
        "/guilds/disciple-of-ferianth/flame-conduit/conduit-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    // Form-only active ability: Blazing Teleport
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/blazing-teleport.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/blazing-teleport.c",
        "/guilds/disciple-of-ferianth/flame-conduit/infernal-veins.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/pyroclastic-form.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/searing-touch.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/pyroclastic-form.c",
        "/guilds/disciple-of-ferianth/flame-conduit/infernal-veins.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/searing-touch.c",
        "/guilds/disciple-of-ferianth/flame-conduit/radiant-presence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    // Form-only passive: Flame Shield (damage reflection while in form)
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/flame-shield.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/flame-shield.c",
        "/guilds/disciple-of-ferianth/flame-conduit/pyroclastic-form.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/living-flame.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/living-flame.c",
        "/guilds/disciple-of-ferianth/flame-conduit/pyroclastic-form.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    // Form-only active ability: Inferno Nova (AoE burst)
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/inferno-nova.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/inferno-nova.c",
        "/guilds/disciple-of-ferianth/flame-conduit/living-flame.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/molten-core.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/elemental-fury.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/molten-core.c",
        "/guilds/disciple-of-ferianth/flame-conduit/living-flame.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/elemental-fury.c",
        "/guilds/disciple-of-ferianth/flame-conduit/searing-touch.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    // Form-only passive: Combustion Aura (enemies take damage when near)
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/combustion-aura.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/combustion-aura.c",
        "/guilds/disciple-of-ferianth/flame-conduit/elemental-fury.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/phoenix-essence.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/phoenix-essence.c",
        "/guilds/disciple-of-ferianth/flame-conduit/molten-core.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    // Form-only active ability: Phoenix Rebirth (self-resurrection)
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/phoenix-rebirth.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/phoenix-rebirth.c",
        "/guilds/disciple-of-ferianth/flame-conduit/phoenix-essence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/sun-touched.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/conflagration-body.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/sun-touched.c",
        "/guilds/disciple-of-ferianth/flame-conduit/phoenix-essence.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/conflagration-body.c",
        "/guilds/disciple-of-ferianth/flame-conduit/elemental-fury.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    // Form-only passive: Solar Flare (critical hit bonus while in form)
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/solar-flare.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/solar-flare.c",
        "/guilds/disciple-of-ferianth/flame-conduit/sun-touched.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/primordial-fire.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/primordial-fire.c",
        "/guilds/disciple-of-ferianth/flame-conduit/sun-touched.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/eternal-ember.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/incandescent-soul.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/eternal-ember.c",
        "/guilds/disciple-of-ferianth/flame-conduit/primordial-fire.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/incandescent-soul.c",
        "/guilds/disciple-of-ferianth/flame-conduit/conflagration-body.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/avatar-of-flame.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/undying-pyre.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/avatar-of-flame.c",
        "/guilds/disciple-of-ferianth/flame-conduit/eternal-ember.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/undying-pyre.c",
        "/guilds/disciple-of-ferianth/flame-conduit/incandescent-soul.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/divine-combustion.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/solar-ascendant.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/divine-combustion.c",
        "/guilds/disciple-of-ferianth/flame-conduit/avatar-of-flame.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/solar-ascendant.c",
        "/guilds/disciple-of-ferianth/flame-conduit/undying-pyre.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFifthLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/ferianths-chosen.c");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/immortal-inferno.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/ferianths-chosen.c",
        "/guilds/disciple-of-ferianth/flame-conduit/divine-combustion.c");
    addChild("/guilds/disciple-of-ferianth/flame-conduit/immortal-inferno.c",
        "/guilds/disciple-of-ferianth/flame-conduit/solar-ascendant.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/fire-eternal.c");

    addChild("/guilds/disciple-of-ferianth/flame-conduit/fire-eternal.c",
        "/guilds/disciple-of-ferianth/flame-conduit/ferianths-chosen.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Flame Conduit");
    Description("This research tree provides knowledge of transforming oneself "
        "into a living conduit of Ferianth's sacred fire. Through progressive "
        "stages of transformation, disciples gain fire resistance, burning "
        "auras, and eventually become avatars of flame itself - beings of "
        "pure divine fire walking in mortal form.");
    Source("disciple of ferianth");
    addResearchElement("/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c");
    TreeRoot("/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c");

    FifthLevel();
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
    FortySeventhLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
    FiftySeventhLevel();
    SixtyFirstLevel();
    SixtyFifthLevel();
    SixtySeventhLevel();
}
