main = putStrLn (show ans)
ans = ways 50

ways 0 = 1
ways n = sum $ take (min n 4) $ drop (max (n-4) 0) waysMemo
waysMemo = map ways [0..]