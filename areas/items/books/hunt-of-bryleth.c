//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Hunt of Bryleth");
    set("short", "a weathered journal titled 'The Hunt of Bryleth'");
    set("title",
        "The Hunt of Bryleth: A Record by Sir Uhrdalen");
    set("aliases",
        ({ "bryleth hunt", "uhrdalen journal", "second chronicle",
           "hunt of bryleth", "journal", "book" }));
    set("long",
        "A personal account written in a steady but increasingly "
        "strained hand. This journal chronicles Sir Uhrdalen's hunt "
        "for Bryleth. What begins as certainty slowly erodes into "
        "something far less certain.");

    addChapter("The Charge",
        "I was given a name and a command.\n"
        "\n"
        "Bryleth.\n"
        "\n"
        "Find her. Bind her. End what she represents.\n"
        "\n"
        "There was no hesitation in me. There has never been\n"
        "hesitation. I am not made for it.\n"
        "\n"
        "She is called a deviation. A fracture. A voice that\n"
        "weakens resolve and erodes obedience.\n"
        "\n"
        "If this is true, then she must be ended.\n"
        "\n"
        "This is not judgment. It is function.\n");

    addChapter("The Pursuit",
        "She does not flee as others do.\n"
        "\n"
        "There are signs of her passing, but they are not careless.\n"
        "They are deliberate. Almost... instructive.\n"
        "\n"
        "I follow, and I begin to understand that I am meant to.\n"
        "\n"
        "In one ruined hall, I found words carved into stone:\n"
        "\n"
        "I find no sanctuary.\n"
        "\n"
        "The hand was unsteady. Or perhaps the stone resisted.\n"
        "\n"
        "It is irrelevant.\n"
        "\n"
        "And yet, I remained there longer than necessary.\n");

    addChapter("First Encounter",
        "I found her at the edge of a shattered valley.\n"
        "\n"
        "She did not run.\n"
        "\n"
        "She turned to face me, as though she had been waiting.\n"
        "\n"
        "You are far from your masters, she said.\n"
        "\n"
        "Her voice was calm. There was no fear in it.\n"
        "\n"
        "You should not speak, I told her. You should yield.\n"
        "\n"
        "She smiled at this, though there was no warmth in it.\n"
        "\n"
        "You call it strength, she said. I call it fear\n"
        "wearing armor.\n"
        "\n"
        "I struck at her then.\n"
        "\n"
        "She was not there.\n");

    addChapter("Fractures",
        "She appears and vanishes as she wills. Or so it seems.\n"
        "\n"
        "Each encounter leaves nothing behind but words.\n"
        "\n"
        "My phantoms assail me.\n"
        "\n"
        "Held in my tracks by fear.\n"
        "\n"
        "These are not threats. They are not pleas.\n"
        "\n"
        "They are statements.\n"
        "\n"
        "I record them here only to better understand her.\n"
        "\n"
        "Understanding is not sympathy.\n"
        "\n"
        "It is strategy.\n");

    addChapter("Doubt",
        "I do not doubt.\n"
        "\n"
        "This is truth.\n"
        "\n"
        "And yet, there are moments between steps where thought\n"
        "lingers longer than it should.\n"
        "\n"
        "She speaks as though I have chosen this path.\n"
        "\n"
        "This is incorrect.\n"
        "\n"
        "I do not choose. I obey.\n"
        "\n"
        "And yet...\n"
        "\n"
        "If one does not choose, can one be said to be strong?\n"
        "\n"
        "This thought is not mine.\n"
        "\n"
        "It is a flaw.\n");

    addChapter("The Edge",
        "I am close now. I can feel it.\n"
        "\n"
        "She no longer avoids me. She leads me.\n"
        "\n"
        "There is a place ahead. I have seen it in fragments.\n"
        "Stone. Veil. Silence.\n"
        "\n"
        "She will go there.\n"
        "\n"
        "Or perhaps she has always been there, and I am only\n"
        "now permitted to arrive.\n"
        "\n"
        "It does not matter.\n"
        "\n"
        "I will complete my task.\n"
        "\n"
        "I will bind her.\n"
        "\n"
        "I do not understand why I write this.\n"
        "\n"
        "There is no need to record certainty.\n"
        "\n"
        "And yet, I feel that something is ending.\n"
        "\n"
        "Or beginning.\n");
}
