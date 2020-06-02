
<!-- README.md is generated from README.Rmd. Please edit that file -->

<img src="man/figures/sticker.png" align="right" width="15%" height="15%" />

## Overview

The ‘FreeHiCLite’ package is designed for simulate Hi-C contact matrix.

The original package [FreeHi-C](https://github.com/yezhengSTAT/FreeHiC)
is short for **Fr**agment interactions **e**mpirical **e**stimation for
fast simulation of **Hi-C** data. It is a data-driven Hi-C data
simulator for simulating and augmenting Hi-C datasets. FreeHi-C employs
a non-parametric strategy for estimating an interaction distribution of
genome fragments and simulates Hi-C reads from interacting fragments.
Data from FreeHi-C exhibit higher fidelity to the biological Hi-C data.
FreeHi-C not only can be used to study and benchmark a wide range of
Hi-C analysis methods but also boosts power and enables false discovery
rate control for differential interaction detection algorithms through
data augmentation. Different from FreeHi-C (v1.0), a spike-in module is
added enabling the simulation of true differential chromatin
interactions.

FreeHi-C is designed for studies that are prone to simulate Hi-C
interactions from the real data and add deviations from the true ones.
Therefore, FreeHi-C requires real Hi-C sequencing data (FASTQ format) as
input along with user-defined simulation parameters. FreeHi-C will
eventually provide the simulated genomics contact counts in a sparse
matrix format (BED format) which is compatible with the standard input
of downstream Hi-C analysis.

## Installation

Install the development version using the **devtools** package:

``` r
devtools::install_github("banconzhou/FreeHiCLite")
```

## Usage

Load the package:

``` r
library(FreeHiCLite)
```

### Read hic data

The [`.hic`](https://github.com/aidenlab/juicer/wiki/Data) file is a
highly compressed binary file, which is developed in the [Aiden
Lab](http://aidenlab.org/). Which can be used in
[juicebox](https://aidenlab.org/juicebox/) for contact matrix
visulization.

The `.hic` file is formated as
[HiCFormat](https://github.com/aidenlab/Juicebox/blob/master/HiCFormatV8.md).
To program with `.hic` file, they provide
[straw](https://github.com/aidenlab/straw) and
[Dump](https://github.com/aidenlab/juicer/wiki/Data-Extraction) to
extract the information from the `.hic` file. The
‘FreeHiCLite::readJuicer’ adopts most from the C++ version of
[straw](https://github.com/aidenlab/straw).

The `.hic` file only contains two units of resolution, and each unit
contains a fix set of resolutions.

1.  Base-pair-delimited resolutions (**BP**): 2.5M, 1M, 500K, 250K,
    100K, 50K, 25K, 10K, and 5K.
2.  Fragment-delimited resolutions (**FRAG**): 500f, 250f, 100f, 50f,
    20f, 5f, 2f,
1f.

<!-- end list -->

``` r
## Remote file location. The reomte file include downloading, it may take a while
remoteFilePath = "https://hicfiles.s3.amazonaws.com/hiseq/gm12878/in-situ/combined.hic"
 
## Local file location
localFilePath = system.file("extdata", "example.hic", package = "FreeHiCLite")
 
## Chromosomes needs to be extra
chromosomes = c("chr1", "chr2")

## Pairs needs to be extra
pairs = c("1_1", "1_2")
unit = "BP"
resolution = 500000L
```

#### Extract hic information

We can extract some basic information from a `.hic` file via:

``` r
juicerInfo <- readJuicerInformation(localFilePath, verbose = TRUE)
#> File: /Library/Frameworks/R.framework/Versions/4.0/Resources/library/FreeHiCLite/extdata/example.hic
#> GenomId: hg19
#> Hi-C resolution:
#>     BP: 2500000, 1000000, 500000, 250000, 100000, 50000, 25000, 10000, 5000.
#>     FRAG not avaiable.
```

Besides, `juicerInfo` also provides chromsome size information, if the
genomeID is not one of the genome they provided. [check
here](https://github.com/aidenlab/juicer/wiki/Pre#usage)

``` r
head(juicerInfo[["chromosomeSizes"]])
#>   chromosome      size
#> 1          1 249250621
#> 2         10 135534747
#> 3         11 135006516
#> 4         12 133851895
#> 5         13 115169878
#> 6         14 107349540
```

#### Read hic file

To read a remote `.hic` file. Provide a remote url to `readJuicer()`.
The full list of remote links can be found in
<http://aidenlab.org/data.html>.

``` r
## pass chrosomes into function, it will contains all the interaction pairs
datRemote <- readJuicer(file=remoteFilePath, chromosomes=chromosomes, pairs = NULL, unit=unit, resolution=resolution)
```

``` r
## pass chrosomes into function, it will contains all the interaction pairs
datLoc <- readJuicer(file=localFilePath, chromosomes=chromosomes, pairs = NULL, unit=unit, resolution=resolution)
#> You are trying to access file from: /Library/Frameworks/R.framework/Versions/4.0/Resources/library/FreeHiCLite/extdata/example.hic. Make sure you provide a valid path.
#> Use pairs: 1_1, 1_2, 2_2
str(datLoc)
#> List of 3
#>  $ contact    :List of 3
#>   ..$ 1_1: int [1:26875, 1:3] 0 0 500000 0 500000 1000000 500000 1000000 1500000 500000 ...
#>   .. ..- attr(*, "dimnames")=List of 2
#>   .. .. ..$ : NULL
#>   .. .. ..$ : chr [1:3] "x" "y" "counts"
#>   ..$ 1_2: int [1:7551, 1:3] 27000000 34000000 50000000 50500000 57500000 66000000 167500000 175500000 244000000 245000000 ...
#>   .. ..- attr(*, "dimnames")=List of 2
#>   .. .. ..$ : NULL
#>   .. .. ..$ : chr [1:3] "x" "y" "counts"
#>   ..$ 2_2: int [1:28005, 1:3] 0 0 500000 0 500000 1000000 0 500000 1000000 1500000 ...
#>   .. ..- attr(*, "dimnames")=List of 2
#>   .. .. ..$ : NULL
#>   .. .. ..$ : chr [1:3] "x" "y" "counts"
#>  $ information:List of 3
#>   ..$ genomId        : chr "hg19"
#>   ..$ resolution     :List of 2
#>   .. ..$ BP  : int [1:9] 2500000 1000000 500000 250000 100000 50000 25000 10000 5000
#>   .. ..$ FRAG: int(0) 
#>   ..$ chromosomeSizes:'data.frame':  26 obs. of  2 variables:
#>   .. ..$ chromosome: chr [1:26] "1" "10" "11" "12" ...
#>   .. ..$ size      : int [1:26] 249250621 135534747 135006516 133851895 115169878 107349540 102531392 90354753 81195210 78077248 ...
#>  $ settings   :List of 4
#>   ..$ unit       : chr "BP"
#>   ..$ resolution : int 500000
#>   ..$ chromosomes: chr [1:2] "chr1" "chr2"
#>   ..$ file       : chr "/Library/Frameworks/R.framework/Versions/4.0/Resources/library/FreeHiCLite/extdata/example.hic"
#>  - attr(*, "class")= chr [1:2] "juicer" "freehic"
```

#### Write to disk file

The [juicebox](https://aidenlab.org/juicebox/) also provide a function
[Pre](https://github.com/aidenlab/juicer/wiki/Pre) to generate `.hic`
file from different format. In ‘FreeHiCLite’, we provide a function
`writeJuicer()` to write the contact matrix into a [short with score
format](https://github.com/aidenlab/juicer/wiki/Pre#short-with-score-format).
You can use `convertJuicer()` to view the matrix, or directly use
`writeJuicer()`.

``` r
head(convertJuicer(datLoc[['contact']][[1]], "1", "1"))
#>   str1 chr1    pos1 frag1 str2 chr2    pos2 frag2 score
#> 1    0    1       0     0    0    1       0     0    19
#> 2    0    1       0     0    0    1  500000     0    14
#> 3    0    1  500000     0    0    1  500000     0    88
#> 4    0    1       0     0    0    1 1000000     0     1
#> 5    0    1  500000     0    0    1 1000000     0    29
#> 6    0    1 1000000     0    0    1 1000000     0   159
```

``` r
writeJuicer(datLoc, file, overwrite = TRUE)
```

### Add spikeIn

To add spikeIn into contact matrix. The ‘FreeHiCLite’ provides
`FreeSpikeIn(contactBackground, contactSpikeInSignal)` to add spikein.

``` r
kernelSmooth = TRUE
bandwith = 50000L

## Create a random spikeIn

contact <- datLoc[['contact']][[1]]
Ns <- 0.1 * NROW(contact)
spikeIn <- contact[sample(1:NROW(contact), Ns), ]
spikeIn[,3] <- spikeIn[,3] * sample(seq(0, 10, 0.5), Ns, replace=TRUE) # 3rd is the counts

spikeInContact <- FreeSpikeIn(contact, spikeIn, kernelSmooth = kernelSmooth, bandwith = bandwith)
print(summary(contact[,3]))
#>    Min. 1st Qu.  Median    Mean 3rd Qu.    Max. 
#>   1.000   1.000   1.000   5.536   2.000 431.000
print(summary(spikeInContact[,3]))
#>    Min. 1st Qu.  Median    Mean 3rd Qu.    Max. 
#>    1.00    1.00    1.00   29.59    3.00  431.00
```

### Simulate from contact matrix

## References

1.  Ye Zheng and Sündüz Keleş. [“FreeHi-C simulates high-fidelity Hi-C
    data for benchmarking and data
    augmentation.”](https://www.nature.com/articles/s41592-019-0624-3)
    Nature Methods (2019).
2.  Neva C. Durand, Muhammad S. Shamim, Ido Machol, Suhas S. P. Rao,
    Miriam H. Huntley, Eric S. Lander, and Erez Lieberman Aiden.
    [“Juicer provides a one-click system for analyzing loop-resolution
    Hi-C
    experiments.”](https://www.cell.com/cell-systems/fulltext/S2405-4712\(16\)30219-8)
    Cell Systems 3(1), 2016.
