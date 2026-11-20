//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("the voice", "@D@Pain blurs the room, but Vilias's "
        "voice cuts through it. Her whisper is close, intimate, "
        "and impossible to mistake for your own thoughts. "
        "@S@'Focus. You are not finished yet.'");
    addTopic("focus", "@D@You stop fighting every sensation at "
        "once. The orb's dark strands become distinct, and your "
        "will gathers around them. The pain remains, but it no "
        "longer commands your attention. @S@'That is it. Hold "
        "your purpose steady.'");
    addTopic("duna's sacrifice", "@D@The acid stops falling, "
        "but Duna's hand remains raised over you. Each drop "
        "striking her shield draws a small, involuntary sound "
        "from her. Vilias's voice turns sharp. @S@'You can help "
        "her. Stop watching helplessly and use what you have.'");
    addTopic("the orb", "@D@The corruption is not one solid "
        "thing. It reaches through you in dark tendrils, each "
        "one pulling at flesh and spirit. Vilias's command "
        "returns: @S@'Find the strands. Gather them. Make the "
        "power answer to you.'");
    addTopic("breaking free", "@D@The bindings give way only "
        "after you stop spending all your strength on panic. "
        "Your body is wrecked, but you can move. Vilias's voice "
        "is already turning your attention toward Duna.");
    addTopic("find duna", "@S@'Do not run to her empty-handed. "
        "Go to the storage room. I moved weapons there for you "
        "and your companions. Then return to the cells.'");
    addTopic("duna's feelings", "@D@Vilias's first words leave "
        "little room for hope, but her later warning is less "
        "certain. @S@'You do not know her mind. Do not decide "
        "what she feels without asking her.'");
    addTopic("her bargain", "@D@The promise she made while "
        "you were helpless now feels less like kindness than "
        "another move in a game. @S@'I said I would heal you "
        "if you asked sincerely. I will keep my word.'");
    addTopic("the healing", "@D@As Galadhel and Duna tend your "
        "wounds, Vilias's voice presses against your thoughts. "
        "@S@'You hate being dependent on them. Admit that you "
        "need help. I will heal you whether you welcome it or not.'");
    addTopic("her purpose", "@S@'I will risk being condemned "
        "if it keeps the world's souls from being destroyed. "
        "That does not make the choices I forced on you harmless.'");
    addTopic("the dead", "@D@Vilias does not soften her answer. "
        "@S@'The dead are with Mandos. I will not pretend I "
        "chose a painless path, or that I expect you to forgive "
        "the blameless who died.'");
    addTopic("the puppeteer", "@D@Her presence feels close, "
        "but never fully within reach. @S@'I shape events when "
        "I can. I do not own your choices, and I will not ask "
        "you to mistake manipulation for trust.'");

    addResponse("the voice", "Why are you helping me now?",
        "@S@'Because you can still choose what to do with the "
        "power inside you. Do not waste that choice.'");
    addResponseTopic("the voice", "Why are you helping me now?",
        "her bargain");
    addResponse("the voice", "Duna is suffering because of me.",
        "@S@'Then give her more than your despair. Use your "
        "gift to change what happens next.'");
    addResponseTopic("the voice", "Duna is suffering because of me.",
        "duna's sacrifice");
    addResponse("the voice", "I will not let this end here.",
        "@S@'Then focus. Find the part of you that can still act.'");
    addResponseTopic("the voice", "I will not let this end here.",
        "focus");

    addResponse("focus", "How do I control the orb?",
        "@S@'See how it reaches through you. Gather each strand "
        "with your will and force it back toward its source.'");
    addResponseTopic("focus", "How do I control the orb?", "the orb");
    addResponse("focus", "The pain is still there.",
        "@S@'It may remain. You do not need to be free of pain "
        "to choose your next action.'");
    addResponseTopic("focus", "The pain is still there.",
        "breaking free");
    addResponse("the orb", "Can I use this to heal Duna?",
        "@S@'Your gift can mend what is broken. Use it on her "
        "instead of blaming yourself for what she chose to do.'");
    addResponseTopic("the orb", "Can I use this to heal Duna?",
        "duna's sacrifice");
    addResponse("duna's sacrifice", "I should have stopped her.",
        "@S@'You were bound and in pain. Regret will not mend "
        "her. Decide what you can do now.'");
    addResponseTopic("duna's sacrifice",
        "I should have stopped her.", "the orb");

    addResponse("breaking free", "I have to get to Duna.",
        "@S@'First get the weapons. You will need them, and so "
        "will the others.'");
    addResponseTopic("breaking free", "I have to get to Duna.",
        "find duna");
    addResponse("find duna", "Why move our weapons?",
        "@S@'Because I knew you would need them. You need not "
        "approve of my reasons to make use of them.'");
    addResponseTopic("find duna", "Why move our weapons?",
        "the puppeteer");

    addResponse("duna's feelings", "You know she will reject me.",
        "@S@'You do not know that. Ask her when you can speak "
        "without deciding her answer in advance.'");
    addResponseTopic("duna's feelings",
        "You know she will reject me.", "the puppeteer");
    addResponse("duna's feelings", "You are only trying to hurt me.",
        "@S@'Sometimes. This is not one of those times. Do not "
        "turn fear into certainty.'");
    addResponseTopic("duna's feelings",
        "You are only trying to hurt me.", "her purpose");

    addResponse("her bargain", "You caused this pain.",
        "@S@'I did not cause all of it, but I chose to let it "
        "continue. I will not claim otherwise.'");
    addResponseTopic("her bargain", "You caused this pain.",
        "the dead");
    addResponse("her bargain", "Heal me, then.",
        "@S@'You have asked. Be still and let the healing take hold.'");
    addResponseTopic("her bargain", "Heal me, then.", "the healing");
    addResponse("the healing", "I do not need your help.",
        "@S@'You can refuse me. You cannot make the wounds "
        "disappear by refusing to admit they are there.'");
    addResponseTopic("the healing", "I do not need your help.",
        "her bargain");
    addResponse("the healing", "I need help, but not from you.",
        "@S@'Then let the others tend you. I will not make "
        "your choice for you.'");
    addResponseTopic("the healing",
        "I need help, but not from you.", "the puppeteer");

    addResponse("her purpose", "You call this the greater good?",
        "@S@'I call it a choice I made and a burden I will answer "
        "for. I will not ask you to call it good.'");
    addResponseTopic("her purpose", "You call this the greater good?",
        "the dead");
    addResponse("the dead", "You expect me to forgive you?",
        "@S@'No. I expect you to remember what is at stake and "
        "decide for yourself what you can live with.'");
    addResponseTopic("the dead", "You expect me to forgive you?",
        "her purpose");
    addResponse("the puppeteer", "You are playing both sides.",
        "@S@'I am pursuing my own purpose. Whether that makes "
        "me your ally is for you to judge.'");
    addResponseTopic("the puppeteer",
        "You are playing both sides.", "her purpose");
}
