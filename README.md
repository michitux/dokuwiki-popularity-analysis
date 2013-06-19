Plot DokuWiki popularity data submissions over time
===================================================

This is a tool for plotting the timestamps in ``clean_timestamps.txt`` over time.

Compile the script using ``g++ -o average_timestamps average_timestamps.cc``.

Execute the script and generate the plot using

```
cat clean_timestamps.txt | ./average_timestamps > average_submissions.txt
gnuplot average_submissions.plt
```

Optionally you can convert the resulting eps into a pdf using ``epstopdf avg_submissions.eps``.

The timestamps in ``clean_timestamps.txt`` are from http://update.dokuwiki.org/pop/index.php?key=now.
