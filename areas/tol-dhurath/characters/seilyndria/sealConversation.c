//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

private string HoldingRoom =
    "/areas/tol-dhurath/temple-interior/uhrdalen-holding.c";

/////////////////////////////////////////////////////////////////////////////
private void SeilyndriaEmerges()
{
    addTopic("seal broken", "@D@The massive door grinds open, ancient "
        "dust cascading from its frame. Beyond it lies absolute "
        "darkness - and then a figure steps through. A woman, blinking "
        "against the dim light. Her auburn hair, no longer filthy, "
        "cascades around her shoulders. Her pale blue eyes, once "
        "windows into a tortured soul, now gleam with something far "
        "more calculating.\n\n@S@'Maiwyn?!'\n\n@D@The woman you met "
        "in Tol-Dhurath stands before you, but something is profoundly "
        "wrong. She is clean, composed, and radiating an aura of power "
        "that was never there before. A slow, satisfied smile spreads "
        "across her face.\n\n@S@'Oh, you poor dear. You actually "
        "believed all of that, didn't you?'");

    addResponse("seal broken", "How are you here?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::take## a step "
        "back. @S@'How are you here? You were... the prisoners... "
        "what is the meaning of this?'");
    addResponse("seal broken", "What is this?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::stare## at the "
        "woman, a chill running down ##InitiatorPossessive## spine. "
        "@S@'What is this? What have I done?'");
}

/////////////////////////////////////////////////////////////////////////////
private void TheRevelation()
{
    addTopic("revelation", "@D@She laughs - and the sound cracks stone. "
        "Her form ripples, the prisoner's garments dissolving into a "
        "gown woven from twilight itself. Her eyes shift from pale "
        "blue to deep violet. Auburn hair darkens to liquid shadow, "
        "impossibly long and dark.\n\n@S@'I am Seilyndria. Goddess of "
        "Destruction, Mistress of Ruin, She Who Unmakes.' @D@She "
        "examines her hands as though seeing them for the first time "
        "in ages. @S@'The wretched prisoner Maiwyn. The brave woman "
        "too weak to fight. The damsel who needed you to do all the "
        "hard work.' @D@She smirks. @S@'I must say, the performance "
        "was exquisite.'");
    addTopicEvent("revelation", "revealSeilyndria");
    addResponseTopic("seal broken", "How are you here?", "revelation");
    addResponseTopic("seal broken", "What is this?", "revelation");

    addResponse("revelation", "Uhrdalen... he was yours?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::clench## "
        "##InitiatorPossessive## fists. @S@'Uhrdalen... he was "
        "yours? This was all a trap?'");
    addResponse("revelation", "You sent me here to free you.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::whisper##, "
        "@S@'You pointed me at the temple. Told me about the sealed "
        "door. This was never about the outlaws - it was about "
        "freeing you.'");
}

/////////////////////////////////////////////////////////////////////////////
private void TheTruth()
{
    addTopic("the truth", "@D@Seilyndria's smile widens.\n\n@S@'Oh, "
        "Uhrdalen was my most faithful servant. I bound him here as "
        "guardian - and as bait. He played his role perfectly, even "
        "after death stripped away his flesh. The tragic wraith, the "
        "reluctant guide, the voice of wisdom urging you onward.' "
        "@D@She waves a hand dismissively. @S@'The Test of Obedience "
        "was my masterwork. Only someone truly obedient - someone who "
        "would follow every instruction, solve every puzzle, place "
        "every rune, and cut their own flesh without question - could "
        "break my seal.' @D@She leans close, her voice dropping to a "
        "conspiratorial whisper. @S@'I pointed you at the temple, "
        "told you about the sealed door, and watched you walk straight "
        "into my design. I could not have asked for a more obedient "
        "little puppet.'");
    addResponseTopic("revelation", "Uhrdalen... he was yours?",
        "the truth");
    addResponseTopic("revelation", "You sent me here to free you.",
        "the truth");

    addResponse("the truth", "I will stop you.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::straighten##. "
        "@S@'I will find a way to stop you. Whatever you are planning, "
        "I will undo it.'");
    addResponse("the truth", "What do you intend?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## through "
        "gritted teeth, @S@'What do you intend to do?'");
}

/////////////////////////////////////////////////////////////////////////////
private void HerPlans()
{
    addTopic("plans", "@D@Seilyndria laughs again, and this time the "
        "sound cracks the stone beneath her feet.\n\n@S@'Stop me? You "
        "cannot even begin to comprehend what I am.' @D@She begins to "
        "pace, dark energy swirling around her feet. @S@'The world has "
        "had millennia of peace since my imprisonment. It has made them "
        "soft. Complacent. They have forgotten what it means to fear "
        "the dark.' @D@Her eyes blaze with violet fire. @S@'My faithful "
        "still wait for me out there. They have kept the faith through "
        "the long centuries. With them at my side, I shall reclaim what "
        "was stolen from me. Every kingdom, every throne, every last "
        "cowering mortal soul - they will all kneel before Seilyndria, "
        "or they will be unmade.'");
    addResponseTopic("the truth", "I will stop you.", "plans");
    addResponseTopic("the truth", "What do you intend?", "plans");

    addResponse("plans", "You won't succeed.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::set## "
        "##InitiatorPossessive## jaw. @S@'The world is not as helpless "
        "as you think. You will be opposed.'");
    addResponse("plans", "This isn't over.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::glare## at the "
        "goddess. @S@'I freed you. I will find a way to undo it.'");
}

/////////////////////////////////////////////////////////////////////////////
private void SeilyndriaVanishes()
{
    addTopic("vanish", "@D@Seilyndria regards you for a long moment, "
        "her smile never wavering.\n\n@S@'Oh, I do hope you try. It "
        "has been so terribly long since I have had any real "
        "entertainment.' @D@Darkness begins to gather around her, "
        "swirling like a living cloak. Her form dims, becoming a "
        "silhouette of absolute shadow against the purple stone."
        "\n\n@S@'We shall meet again, little mortal. And when we do, "
        "remember this moment - remember that it was your obedience "
        "that set me free.'\n\n@D@The darkness swallows her whole. "
        "Where she stood, there is nothing but a fading echo of "
        "laughter and the lingering scent of ash and violet. You are "
        "alone in the chamber, the weight of what you have unleashed "
        "settling upon your shoulders like a shroud.");
    addResponseTopic("plans", "You won't succeed.", "vanish");
    addResponseTopic("plans", "This isn't over.", "vanish");

    addResponse("vanish", "@I@Continue@E@", "@I@Continue@E@");
    addResponseEffect("vanish", "@I@Continue@E@",
        (["move": HoldingRoom]));
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    SeilyndriaEmerges();
    TheRevelation();
    TheTruth();
    HerPlans();
    SeilyndriaVanishes();
}
