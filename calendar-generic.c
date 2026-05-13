/* ============================================================================================================================================================= *\
                                                                        Calendar events.
                             This is an example of a file containing a few Calendar Events. You may define up to 64 such calendar events.
                        No date validation is made on the dates entered. If you set an event for January 32 2027, it will simply never show up.
                                        This also means that you can temporarily disable an event by setting its Day to 0.
      Leaving a few blanks at the beginning is a good idea since it gives you the time to look at the LED matrix to read the message after you hear the beeps.
\* ============================================================================================================================================================= */

Loop1UInt16 = 0;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  1;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "   Happy New Year !!!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  2;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of February begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    = 15;
ActiveConfig0.Event[Loop1UInt16].Month  =  2;
ActiveConfig0.Event[Loop1UInt16].Jingle =  7;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  This is John's birthday today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    = 14;
ActiveConfig0.Event[Loop1UInt16].Month  =  2;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Happy Valentine's day !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  3;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of March begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  4;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of April begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    = 19;
ActiveConfig0.Event[Loop1UInt16].Month  =  4;
ActiveConfig0.Event[Loop1UInt16].Jingle =  7;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  This is Bill's birthday today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  5;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of May begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  6;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of June begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  7;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of July begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  8;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of August begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  =  9;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of September begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  = 10;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of October begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  = 11;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of November begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    =  1;
ActiveConfig0.Event[Loop1UInt16].Month  = 12;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "  Month of December begins today !!");


++Loop1UInt16;
ActiveConfig0.Event[Loop1UInt16].Day    = 25;
ActiveConfig0.Event[Loop1UInt16].Month  = 12;
ActiveConfig0.Event[Loop1UInt16].Jingle =  0;
sprintf(ActiveConfig0.Event[Loop1UInt16].Message, "    Merry Christmas !!!");
