//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/monk/bludgeon/measured-impact.c");
    addChild("/guilds/monk/bludgeon/measured-impact.c",
        "/guilds/monk/bludgeon/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SecondLevel()
{
    addResearchElement("/guilds/monk/bludgeon/settled-guard.c");
    addChild("/guilds/monk/bludgeon/settled-guard.c",
        "/guilds/monk/bludgeon/measured-impact.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/monk/bludgeon/impact-theory.c");
    addChild("/guilds/monk/bludgeon/impact-theory.c",
        "/guilds/monk/bludgeon/settled-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/grounded-footwork.c");
    addChild("/guilds/monk/bludgeon/grounded-footwork.c",
        "/guilds/monk/bludgeon/impact-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/staff-fulcrum.c");
    addChild("/guilds/monk/bludgeon/staff-fulcrum.c",
        "/guilds/monk/bludgeon/impact-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/balanced-grip.c");
    addChild("/guilds/monk/bludgeon/balanced-grip.c",
        "/guilds/monk/bludgeon/staff-fulcrum.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/monk/bludgeon/mace-head-alignment.c");
    addChild("/guilds/monk/bludgeon/mace-head-alignment.c",
        "/guilds/monk/bludgeon/impact-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/close-haft-grip.c");
    addChild("/guilds/monk/bludgeon/close-haft-grip.c",
        "/guilds/monk/bludgeon/mace-head-alignment.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/hammer-counterweight.c");
    addChild("/guilds/monk/bludgeon/hammer-counterweight.c",
        "/guilds/monk/bludgeon/impact-theory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TenthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/anchored-haft.c");
    addChild("/guilds/monk/bludgeon/anchored-haft.c",
        "/guilds/monk/bludgeon/hammer-counterweight.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwelfthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/sweeping-arc.c");
    addChild("/guilds/monk/bludgeon/sweeping-arc.c",
        "/guilds/monk/bludgeon/balanced-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FourteenthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/turning-staff.c");
    addChild("/guilds/monk/bludgeon/turning-staff.c",
        "/guilds/monk/bludgeon/sweeping-arc.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixteenthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/staff-economy.c");
    addChild("/guilds/monk/bludgeon/staff-economy.c",
        "/guilds/monk/bludgeon/turning-staff.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EighteenthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/compact-blow.c");
    addChild("/guilds/monk/bludgeon/compact-blow.c",
        "/guilds/monk/bludgeon/close-haft-grip.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentiethLevel()
{
    addResearchElement("/guilds/monk/bludgeon/weighted-rhythm.c");
    addChild("/guilds/monk/bludgeon/weighted-rhythm.c",
        "/guilds/monk/bludgeon/compact-blow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySecondLevel()
{
    addResearchElement("/guilds/monk/bludgeon/mace-recovery.c");
    addChild("/guilds/monk/bludgeon/mace-recovery.c",
        "/guilds/monk/bludgeon/weighted-rhythm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFourthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/falling-head.c");
    addChild("/guilds/monk/bludgeon/falling-head.c",
        "/guilds/monk/bludgeon/anchored-haft.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySixthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/rooted-anvil.c");
    addChild("/guilds/monk/bludgeon/rooted-anvil.c",
        "/guilds/monk/bludgeon/falling-head.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyEighthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/hammer-return.c");
    addChild("/guilds/monk/bludgeon/hammer-return.c",
        "/guilds/monk/bludgeon/rooted-anvil.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtiethLevel()
{
    addResearchElement("/guilds/monk/bludgeon/recovery-economy.c");
    addChild("/guilds/monk/bludgeon/recovery-economy.c",
        "/guilds/monk/bludgeon/grounded-footwork.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySecondLevel()
{
    addResearchElement("/guilds/monk/bludgeon/returning-guard.c");
    addChild("/guilds/monk/bludgeon/returning-guard.c",
        "/guilds/monk/bludgeon/recovery-economy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFourthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/crossbar-defense.c");
    addChild("/guilds/monk/bludgeon/crossbar-defense.c",
        "/guilds/monk/bludgeon/turning-staff.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySixthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/haft-shelter.c");
    addChild("/guilds/monk/bludgeon/haft-shelter.c",
        "/guilds/monk/bludgeon/weighted-rhythm.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyEighthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/braced-recovery.c");
    addChild("/guilds/monk/bludgeon/braced-recovery.c",
        "/guilds/monk/bludgeon/rooted-anvil.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortiethLevel()
{
    addResearchElement("/guilds/monk/bludgeon/leverage-study.c");
    addChild("/guilds/monk/bludgeon/leverage-study.c",
        "/guilds/monk/bludgeon/returning-guard.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySecondLevel()
{
    addResearchElement("/guilds/monk/bludgeon/draining-impact.c");
    addChild("/guilds/monk/bludgeon/draining-impact.c",
        "/guilds/monk/bludgeon/leverage-study.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFourthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/pressing-shaft.c");
    addChild("/guilds/monk/bludgeon/pressing-shaft.c",
        "/guilds/monk/bludgeon/staff-economy.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySixthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/long-reach-geometry.c");
    addChild("/guilds/monk/bludgeon/long-reach-geometry.c",
        "/guilds/monk/bludgeon/pressing-shaft.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyEighthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/taxing-contact.c");
    addChild("/guilds/monk/bludgeon/taxing-contact.c",
        "/guilds/monk/bludgeon/mace-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftiethLevel()
{
    addResearchElement("/guilds/monk/bludgeon/contact-geometry.c");
    addChild("/guilds/monk/bludgeon/contact-geometry.c",
        "/guilds/monk/bludgeon/taxing-contact.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySecondLevel()
{
    addResearchElement("/guilds/monk/bludgeon/burdening-blow.c");
    addChild("/guilds/monk/bludgeon/burdening-blow.c",
        "/guilds/monk/bludgeon/hammer-return.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFourthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/anvil-geometry.c");
    addChild("/guilds/monk/bludgeon/anvil-geometry.c",
        "/guilds/monk/bludgeon/burdening-blow.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySixthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/staff-equilibrium.c");
    addChild("/guilds/monk/bludgeon/staff-equilibrium.c",
        "/guilds/monk/bludgeon/long-reach-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyEighthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/mace-composure.c");
    addChild("/guilds/monk/bludgeon/mace-composure.c",
        "/guilds/monk/bludgeon/contact-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtiethLevel()
{
    addResearchElement("/guilds/monk/bludgeon/hammer-poise.c");
    addChild("/guilds/monk/bludgeon/hammer-poise.c",
        "/guilds/monk/bludgeon/anvil-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySecondLevel()
{
    addResearchElement("/guilds/monk/bludgeon/momentum-mastery.c");
    addChild("/guilds/monk/bludgeon/momentum-mastery.c",
        "/guilds/monk/bludgeon/draining-impact.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFourthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/horizon-stroke.c");
    addChild("/guilds/monk/bludgeon/horizon-stroke.c",
        "/guilds/monk/bludgeon/long-reach-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySixthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/centerline-crush.c");
    addChild("/guilds/monk/bludgeon/centerline-crush.c",
        "/guilds/monk/bludgeon/contact-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyEighthLevel()
{
    addResearchElement("/guilds/monk/bludgeon/anvil-descent.c");
    addChild("/guilds/monk/bludgeon/anvil-descent.c",
        "/guilds/monk/bludgeon/anvil-geometry.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventiethLevel()
{
    addResearchElement("/guilds/monk/bludgeon/unbroken-cadence.c");
    addChild("/guilds/monk/bludgeon/unbroken-cadence.c",
        "/guilds/monk/bludgeon/momentum-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("bludgeon discipline");
    Description("Controlled impacts and recovery shared by staffs, maces, and "
        "hammers.");
    Source("monk");
    deferResearchLoading();

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addResearchElement("/guilds/monk/bludgeon/root.c");
    TreeRoot("/guilds/monk/bludgeon/root.c");

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
    FourteenthLevel();
    SixteenthLevel();
    EighteenthLevel();
    TwentiethLevel();
    TwentySecondLevel();
    TwentyFourthLevel();
    TwentySixthLevel();
    TwentyEighthLevel();
    ThirtiethLevel();
    ThirtySecondLevel();
    ThirtyFourthLevel();
    ThirtySixthLevel();
    ThirtyEighthLevel();
    FortiethLevel();
    FortySecondLevel();
    FortyFourthLevel();
    FortySixthLevel();
    FortyEighthLevel();
    FiftiethLevel();
    FiftySecondLevel();
    FiftyFourthLevel();
    FiftySixthLevel();
    FiftyEighthLevel();
    SixtiethLevel();
    SixtySecondLevel();
    SixtyFourthLevel();
    SixtySixthLevel();
    SixtyEighthLevel();
    SeventiethLevel();
}
