# Teensy_music_remote

A program to recreate three keyboard button combinations
on the attached computer, so as to control music playback
via foobar 2000 software. This requires setting the key combos
in foobar's configuration as well. 

## Key combos
 Ctrl+Shift+Alt+F10 key combo == Play or Pause
 Ctrl+Shift+Alt+F11 key combo == Next song 
 Ctrl+Shift+Alt+F9 key combo == Previous song

## Setting up foobar 2000 to recognize the key combos
 Enter these key combos in foobar's Configure>General>Keyboard Shortcuts
 menu. Hit "Add New" in the upper section. Find the desired Action
 in the lower section. It may be helpful to filter by "Play" and look
 in the Playback section. Select the desired action. Then type the 
 key combo in the Key entry field in the lower section, and check 
 the Global Hotkey box so that the key combo is recognized regardless
 of what other program has focus at any given time. 
