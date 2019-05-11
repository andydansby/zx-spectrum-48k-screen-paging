cls

del *.bin
del *.map
del *.def
del *.lst

apack screen1.scr screen1.bin
apack screen2.scr screen2.bin

zcc +zx -vn -O3 -zorg=24600 main.c  -lndos -o -create-app -m